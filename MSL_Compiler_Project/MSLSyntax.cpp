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

bool SyntaxAnalyzerUtility::program(vector<Word>* program) {
	if (program->at(0).getIdentifier() == T_RESERVE) {
		program->erase(program->begin());
		if (program->at(0).getIdentifier() == T_INT)
			program->erase(program->begin());
		else
			return false;
	}
	//TODO
	return true;
}


#pragma endregion
