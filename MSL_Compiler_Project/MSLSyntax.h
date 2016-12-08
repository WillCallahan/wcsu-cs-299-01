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
						static bool program(vector<Word>* program);
						static bool procDec(vector<Word>* procDec);
						static bool series(vector<Word>* series);
						static bool statement(vector<Word>* statement);
						static bool assign(vector<Word>* assign);
						static bool whileWords(vector<Word>* whileWords);
						static bool ifWords(vector<Word>* ifWords);
						static bool call(vector<Word>* call);
						static bool read(vector<Word>* read);
						static bool write(vector<Word>* write);
						static bool expression(vector<Word>* expression);
						static bool operand(vector<Word>* operand);
						static bool variable(vector<Word>* variable);
					};

				}
			}
		}
	}
}
