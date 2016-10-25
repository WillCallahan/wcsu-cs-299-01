#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace edu {
	namespace wcsu {
		namespace cs {
			namespace msl {

#define NEW_LINE '\n'
#define CARRAGE_RETURN '\r'
#define SPACE ' '

#define T_LEFT_PAREN '('
#define T_RIGHT_PAREN ')'
#define T_COMPARE '='
#define T_DIVIDE '/'
#define T_MULT '*'
#define T_PLUS '+'
#define T_MINUS '-'
#define T_SEMICOLON ';'
#define T_PERIOD '.'
#define T_NOT '!'

#define T_WHILE 256
#define T_DO 257
#define T_IF 258
#define T_THEN 259
#define T_ELSE 260
#define T_FI 261

#define T_RESERVE 300
#define T_PROC 301
#define T_END 302
#define T_CALL 303
#define T_READ 304
#define T_WRITE 305
#define T_ASSIGN 306

				class TerminalConverter {
				private:
					TerminalConverter();
				public:
					static string getStringValue(const int&);
					static int getIntValue(const string&);
					static vector<string>* asStringVector();
					static vector<int>* asIntVector();
					static vector<string>* getMatches(const string);
					static vector<string>* getSpecialStringVector();
					static vector<string>* getMatchesSpecialString(const string);
				};

				class LexicalAnalysis {
				private:
					string* text;
					LexicalAnalysis();
				public:
					LexicalAnalysis(string* text);
					void setText(string* text);
					string* getText() const;
					vector<string> getLexemeVector() const;
				};

			}
		}
	}
}

