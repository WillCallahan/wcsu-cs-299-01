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

SyntaxAnalyzerUtility::SyntaxAnalyzerUtility() {
	
}

int SyntaxAnalyzerUtility::program(vector<Word>* program, int index) {
	if (program->at(index).getIdentifier() == T_RESERVE) {
		index++;
		if (program->at(index).getIdentifier() == T_INT)
			index++;
		else
			throw illegal_token(program->at(index).getIdentifier());
	}
	if ((index = procDec(program, ++index)) < program->size() && program->at(index).getIdentifier() == T_COMMA)
		return index;
	throw illegal_token(program->at(index).getIdentifier());
}

int SyntaxAnalyzerUtility::procDec(vector<Word>* procDec, int index) {
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
	throw illegal_token(procDec->at(index).getIdentifier());
}

int SyntaxAnalyzerUtility::series(vector<Word>* series, int index) {
	int matchIndex;
	while ((matchIndex = statement(series, index)) != index)
		index = matchIndex;
	return index;
}

int SyntaxAnalyzerUtility::statement(vector<Word>* statement, int index) {
	int matchIndex;
	if ((matchIndex = assign(statement, index)) != index)
		return matchIndex;
	else if ((matchIndex = whileWords(statement, index)) != index)
		return matchIndex;
	else if ((matchIndex = ifWords(statement, index)) != index)
		return matchIndex;
	else if ((matchIndex = call(statement, index)) != index)
		return matchIndex;
	else if ((matchIndex = read(statement, index)) != index)
		return matchIndex;
	else if ((matchIndex = write(statement, index)) != index)
		return matchIndex;
	else
		return index;
}

int SyntaxAnalyzerUtility::assign(vector<Word>* assign, int index) {
	if (assign->at(index).getIdentifier() == T_VARIABLE) {
		if (assign->at(++index).getIdentifier() == T_ASSIGN) {
			if ((index = expression(assign, ++index)))
				return index;
		}
	}
	return index;
}

int SyntaxAnalyzerUtility::whileWords(vector<Word>* whileWords, int index) {
}

int SyntaxAnalyzerUtility::ifWords(vector<Word>* ifWords, int index) {
}

int SyntaxAnalyzerUtility::call(vector<Word>* call, int index) {
}

int SyntaxAnalyzerUtility::read(vector<Word>* read, int index) {
}

int SyntaxAnalyzerUtility::write(vector<Word>* write, int index) {
	int matchIndex;
	if (write->at(index).getIdentifier() == T_WRITE) {
		if (write->at(index + 1).getIdentifier() == T_HASH)
			++index;
		if ((matchIndex = expression(write, index)) != index) {
			//TODO Complete this
		}
	}
}

int SyntaxAnalyzerUtility::expression(vector<Word>* expression, int index) {
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

int SyntaxAnalyzerUtility::operand(vector<Word>* operand, int index) {
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

int SyntaxAnalyzerUtility::variable(vector<Word>* variable, int index) {
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

int SyntaxAnalyzerUtility::methodParameters(vector<Word>* methodParameters, int index) {
	if (methodParameters->at(index).getIdentifier() == T_COMMA) {
		if (methodParameters->at(++index).getIdentifier() == T_IDENTIFIER) {
			return SyntaxAnalyzerUtility::methodParameters(methodParameters, ++index);
		}
	}
	return index;
}

int SyntaxAnalyzerUtility::variableExpressions(vector<Word>* variableExpressions, int index) {
	int matchIndex;
	if (variableExpressions->at(index).getIdentifier() == T_COMMA) {
		if (variableExpressions->at(index + 1).getIdentifier() == T_HASH)
			++index;
		if ((matchIndex = expression(variableExpressions, index + 1)))
	}
}

#pragma endregion
