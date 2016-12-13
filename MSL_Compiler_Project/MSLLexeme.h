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
				namespace service {

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
#define T_COMMA ','
#define T_HASH '#'

#define T_WHILE 256
#define T_DO 257
#define T_IF 258
#define T_THEN 259
#define T_ELSE 260
#define T_FI 261
#define T_OD 262

#define T_RESERVE 300
#define T_PROC 301
#define T_END 302
#define T_CALL 303
#define T_READ 304
#define T_WRITE 305
#define T_ASSIGN 306

#define T_TEXT 350
#define T_INT 351
#define T_OPERATOR 352
#define T_IDENTIFIER 353

					class Word {
					private:
						int identifier; //ID referencing a token
						string value; //Value of the word
					public:
						Word(int identifier, string value);
						int getIdentifier() const;
						string getValue() const;
					};

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
						~LexicalAnalysis();
						void setText(string* text);
						string* getText() const;
						vector<string> getLexemeVector() const;
						static vector<Word> getWordVector(vector<string> terminalVector);
					};
				}
			}
		}
	}
}

