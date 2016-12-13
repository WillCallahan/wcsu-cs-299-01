#pragma once
#include <string>
#include "MSLLexeme.h"

using namespace std;

namespace edu {
	namespace wcsu {
		namespace cs {
			namespace msl {
				namespace service {

					class illegal_token : public exception {
					private:
						int token;
					public:
						illegal_token(int token);
						const char* what() const throw() override;
					};

					class SyntaxAnalyzerUtility {
					private:
						SyntaxAnalyzerUtility();
					public:
						static int program(vector<Word>* program, const int constIndex);
						static int procDec(vector<Word>* procDec, const int constIndex);
						static int series(vector<Word>* series, const int constIndex);
						static int statement(vector<Word>* statement, const int constIndex);
						static int assign(vector<Word>* assign, const int constIndex);
						static int whileWords(vector<Word>* whileWords, const int constIndex);
						static int ifWords(vector<Word>* ifWords, const int constIndex);
						static int call(vector<Word>* call, const int constIndex);
						static int read(vector<Word>* read, const int constIndex);
						static int write(vector<Word>* write, const int constIndex);
						static int expression(vector<Word>* expression, const int constIndex);
						static int operand(vector<Word>* operand, const int constIndex);
						static int variable(vector<Word>* variable, const int constIndex);
					private:
						static int methodParameters(vector<Word>* methodParameters, const int constIndex);
						static int variableExpressionsWithHash(vector<Word>* variableExpressions, const int constIndex);
						static int variableExpressionsWithoutHash(vector<Word>* variableExpressionsWithoutHash, const int constIndex);
						static int variableVariablesWithHash(vector<Word>* variableVariabless, const int constIndex);
					};

				}
			}
		}
	}
}
