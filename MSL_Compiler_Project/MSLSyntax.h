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
						static int program(vector<Word>* program, int index);
						static int procDec(vector<Word>* procDec, int index);
						static int series(vector<Word>* series, int index);
						static int statement(vector<Word>* statement, int index);
						static int assign(vector<Word>* assign, int index);
						static int whileWords(vector<Word>* whileWords, int index);
						static int ifWords(vector<Word>* ifWords, int index);
						static int call(vector<Word>* call, int index);
						static int read(vector<Word>* read, int index);
						static int write(vector<Word>* write, int index);
						static int expression(vector<Word>* expression, int index);
						static int operand(vector<Word>* operand, int index);
						static int variable(vector<Word>* variable, int index);
						static int methodParameters(vector<Word>* methodParameters, int index);
					};

				}
			}
		}
	}
}
