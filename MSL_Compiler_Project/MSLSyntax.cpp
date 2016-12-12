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
					if (procDec->at(++index).getIdentifier() == T_RIGHT_PAREN) {
						if ((index = series(procDec, ++index))) {
							if (procDec->at(++index).getIdentifier() == T_END) {
								return index;
							}
						}
					}
				}
			}
		}
	}
	throw new illegal_token(procDec->at(index).getIdentifier());
}

int SyntaxAnalyzerUtility::series(vector<Word>* series, int index) {
}

int SyntaxAnalyzerUtility::statement(vector<Word>* statement, int index) {
}

int SyntaxAnalyzerUtility::assign(vector<Word>* assign, int index) {
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
}

int SyntaxAnalyzerUtility::expression(vector<Word>* expression, int index) {
}

int SyntaxAnalyzerUtility::operand(vector<Word>* operand, int index) {
}

int SyntaxAnalyzerUtility::variable(vector<Word>* variable, int index) {
}

int SyntaxAnalyzerUtility::methodParameters(vector<Word>* methodParameters, int index) {
	if (methodParameters->at(index).getIdentifier() == T_COMMA) {
		
	}
}

#pragma endregion
