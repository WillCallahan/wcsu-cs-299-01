#include "MSLSyntax.h"
#include <stdexcept>

using namespace edu::wcsu::cs::msl::service;
using namespace std;

#pragma region illegal_token

illegal_token::illegal_token(int token) {
	exception("Invalid token sequence; expected a " + token);
	this->token = token;
}

const char* illegal_token::what() const {
	return "Invalid token sequence; expected a " + token;
}

#pragma endregion

#pragma region SyntaxAnalyzerUtility

#pragma region Constructors

SyntaxAnalyzerUtility::SyntaxAnalyzerUtility() {
	
}

#pragma endregion 

#pragma region public methods

int SyntaxAnalyzerUtility::program(vector<Word>* program, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (program->at(index).getIdentifier() == T_RESERVE) {
		if (program->at(++index).getIdentifier() == T_INT);
		else
			--index;
	}
	while ((matchIndex = procDec(program, index)) != index)
		index = matchIndex;
	if ((matchIndex = series(program, index)) != index)
		index = matchIndex;
	else
		return constIndex;
	if (program->at(index).getIdentifier() == T_PERIOD)
		return index;
	else
		return constIndex;
}

int SyntaxAnalyzerUtility::procDec(vector<Word>* procDec, const int constIndex) {
	int index = constIndex;
	if (procDec->at(index).getIdentifier() == T_PROC) {
		if (procDec->at(++index).getIdentifier() == T_IDENTIFIER) {
			if (procDec->at(++index).getIdentifier() == T_LEFT_PAREN) {
				if ((index = methodParameters(procDec, ++index))) {
					if (procDec->at(index).getIdentifier() == T_RIGHT_PAREN) {
						if ((index = series(procDec, ++index))) {
							if (procDec->at(index).getIdentifier() == T_END) {
								return ++index;
							}
						}
					}
				}
			}
		}
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::series(vector<Word>* series, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	while ((matchIndex = statement(series, index)) != index)
		index = matchIndex;
	return index;
}

int SyntaxAnalyzerUtility::statement(vector<Word>* statement, const int constIndex) {
	int matchIndex;
	if ((matchIndex = assign(statement, constIndex)) != constIndex)
		return matchIndex;
	else if ((matchIndex = whileWords(statement, constIndex)) != constIndex)
		return matchIndex;
	else if ((matchIndex = ifWords(statement, constIndex)) != constIndex)
		return matchIndex;
	else if ((matchIndex = call(statement, constIndex)) != constIndex)
		return matchIndex;
	else if ((matchIndex = read(statement, constIndex)) != constIndex)
		return matchIndex;
	else if ((matchIndex = write(statement, constIndex)) != constIndex)
		return matchIndex;
	return constIndex;
}

int SyntaxAnalyzerUtility::assign(vector<Word>* assign, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if ((matchIndex = variable(assign, index)) != index) {
		index = matchIndex;
		if (assign->at(++index).getIdentifier() == T_ASSIGN) {
			if ((matchIndex = expression(assign, ++index)) != index)
				return matchIndex;
		}
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::whileWords(vector<Word>* whileWords, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (whileWords->at(index).getIdentifier() == T_WHILE) {
		if ((matchIndex = expression(whileWords, ++index)) != index) {
			index = matchIndex;
			if (whileWords->at(index).getIdentifier() == T_DO) {
				if ((matchIndex = series(whileWords, ++index)) != index) {
					index = matchIndex;
					if (whileWords->at(index).getIdentifier() == T_OD)
						return ++index;
				}
			}
		}
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::ifWords(vector<Word>* ifWords, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (ifWords->at(index).getIdentifier() == T_IF) {
		if ((matchIndex = expression(ifWords, ++index)) != index) {
			index = matchIndex;
			if (ifWords->at(index).getIdentifier() == T_THEN) {
				if ((matchIndex = series(ifWords, ++index)) != index) {
					index = matchIndex;
					if (ifWords->at(index).getIdentifier() == T_ELSE) {
						if ((matchIndex = series(ifWords, ++index)) != index)
							index = matchIndex;
						else
							return constIndex;
					}
					if (ifWords->at(index).getIdentifier() == T_FI)
						return index;
				}
			}
		}
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::call(vector<Word>* call, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (call->at(index).getIdentifier() == T_CALL) {
		if (call->at(++index).getIdentifier() == T_IDENTIFIER) {
			if (call->at(index + 1).getIdentifier() == T_LEFT_PAREN) {
				if ((matchIndex = expression(call, index + 2)) != index + 2) {
					matchIndex = variableExpressionsWithoutHash(call, matchIndex);
					if (call->at(matchIndex).getIdentifier() == T_RIGHT_PAREN) {
						return matchIndex;
					}
				}
				return index;
			}
			return ++index;
		}
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::read(vector<Word>* read, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (read->at(index).getIdentifier() == T_READ) {
		if (read->at(index + 1).getIdentifier() == T_HASH)
			++index;
		if ((matchIndex = variable(read, ++index)) != index)
			return variableVariablesWithHash(read, matchIndex);
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::write(vector<Word>* write, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (write->at(index).getIdentifier() == T_WRITE) {
		if (write->at(index + 1).getIdentifier() == T_HASH)
			++index;
		if ((matchIndex = expression(write, ++index)) != index)
			return variableExpressionsWithHash(write, matchIndex);
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::expression(vector<Word>* expression, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if ((matchIndex = operand(expression, index)) != index) {
		index = matchIndex;
		if (expression->at(++matchIndex).getIdentifier() == T_OPERATOR) {
			if ((matchIndex = operand(expression, ++matchIndex)) != index + 2) {
				index = matchIndex;
			}
		}

	}
	return index;
}

int SyntaxAnalyzerUtility::operand(vector<Word>* operand, const int constIndex) {
	int index = constIndex;
	int matchIndex = index;
	if (operand->at(index).getIdentifier() == T_INT)
		return ++index;
	else if (operand->at(index).getIdentifier() == T_TEXT)
		return ++index;
	else if ((matchIndex = variable(operand, index)) != index)
		return matchIndex;
	else if (operand->at(index).getIdentifier() == T_LEFT_PAREN) {
		if ((matchIndex = expression(operand, ++index)) != index) {
			if (operand->at(index).getIdentifier() == T_RIGHT_PAREN) {
				return ++index;
			}
		}
	}
	return index;
}

int SyntaxAnalyzerUtility::variable(vector<Word>* variable, const int constIndex) {
	int index = constIndex;
	if (variable->at(index).getIdentifier() == T_IDENTIFIER) {
		if (variable->at(index + 1).getIdentifier() == T_NOT) {
			int matchIndex = index + 2;
			if ((matchIndex = operand(variable, matchIndex)) != index + 2)
				index = matchIndex;
		}
		return ++index;
	}
	return index;
}

#pragma endregion 

#pragma region private methods

int SyntaxAnalyzerUtility::methodParameters(vector<Word>* methodParameters, const int constIndex) {
	int index = constIndex;
	if (methodParameters->at(index).getIdentifier() == T_COMMA) {
		if (methodParameters->at(++index).getIdentifier() == T_IDENTIFIER) {
			return SyntaxAnalyzerUtility::methodParameters(methodParameters, ++index);
		}
	}
	return index;
}

int SyntaxAnalyzerUtility::variableExpressionsWithoutHash(vector<Word>* variableExpressionsWithoutHash, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (variableExpressionsWithoutHash->at(index).getIdentifier() == T_COMMA) {
		if ((matchIndex = expression(variableExpressionsWithoutHash, ++index)) != index)
			return SyntaxAnalyzerUtility::variableExpressionsWithoutHash(variableExpressionsWithoutHash, constIndex);
	}
	return constIndex;
}


int SyntaxAnalyzerUtility::variableExpressionsWithHash(vector<Word>* variableExpressionsWithHash, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (variableExpressionsWithHash->at(index).getIdentifier() == T_COMMA) {
		if (variableExpressionsWithHash->at(index + 1).getIdentifier() == T_HASH)
			++index;
		if ((matchIndex = expression(variableExpressionsWithHash, ++index)) != index)
			return SyntaxAnalyzerUtility::variableExpressionsWithHash(variableExpressionsWithHash, constIndex);
	}
	return constIndex;
}

int SyntaxAnalyzerUtility::variableVariablesWithHash(vector<Word>* variableVariablesWithHash, const int constIndex) {
	int index = constIndex;
	int matchIndex;
	if (variableVariablesWithHash->at(index).getIdentifier() == T_COMMA) {
		if (variableVariablesWithHash->at(index + 1).getIdentifier() == T_HASH)
			++index;
		if ((matchIndex = variable(variableVariablesWithHash, ++index)) != index)
			return SyntaxAnalyzerUtility::variableVariablesWithHash(variableVariablesWithHash, constIndex);
	}
	return constIndex;
}

#pragma endregion 

#pragma endregion
