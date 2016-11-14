#include "MSLLexeme.h"
#include <stdexcept>

using namespace edu::wcsu::cs::msl::service;
using namespace std;

#pragma region TokenMap

Word::Word(int identifier, string value) {
	this->identifier = identifier;
	this->value = value;
}

int Word::getIdentifier() const {
	return identifier;
}

string Word::getValue() const {
	return value;
}

#pragma endregion 

#pragma region Terminal Converter

TerminalConverter::TerminalConverter() {
}

string TerminalConverter::getStringValue(const int& terminal) {
	switch (terminal) {
	case T_LEFT_PAREN:
		return string(1, T_LEFT_PAREN);
	case T_RIGHT_PAREN:
		return string(1, T_RIGHT_PAREN);
	case T_COMPARE:
		return string(1, T_COMPARE);
	case T_DIVIDE:
		return string(1, T_DIVIDE);
	case T_MULT:
		return string(1, T_MULT);
	case T_PLUS:
		return string(1, T_PLUS);
	case T_MINUS:
		return string(1, T_MINUS);
	case T_SEMICOLON:
		return string(1, T_SEMICOLON);
	case T_PERIOD:
		return string(1, T_PERIOD);
	case T_NOT:
		return string(1, T_NOT);
	case T_WHILE:
		return "WHILE";
	case T_DO:
		return "DO";
	case T_IF:
		return "IF";
	case T_THEN:
		return "THEN";
	case T_ELSE:
		return "ELSE";
	case T_FI:
		return "FI";
	case T_RESERVE:
		return "RESERVE";
	case T_PROC:
		return "PROC";
	case T_END:
		return "END";
	case T_CALL:
		return "CALL";
	case T_READ:
		return "READ";
	case T_WRITE:
		return "WRITE";
	case T_ASSIGN:
		return ":=";
	default:
		throw invalid_argument("Terminal not found!");
	}
}

int TerminalConverter::getIntValue(const string& terminal) {
	if (terminal == getStringValue(T_LEFT_PAREN))
		return T_LEFT_PAREN;
	else if (terminal == getStringValue(T_RIGHT_PAREN))
		return T_RIGHT_PAREN;
	else if (terminal == getStringValue(T_COMPARE))
		return T_COMPARE;
	else if (terminal == getStringValue(T_DIVIDE))
		return T_DIVIDE;
	else if (terminal == getStringValue(T_MULT))
		return T_MULT;
	else if (terminal == getStringValue(T_PLUS))
		return T_PLUS;
	else if (terminal == getStringValue(T_MINUS))
		return T_MINUS;
	else if (terminal == getStringValue(T_SEMICOLON))
		return T_SEMICOLON;
	else if (terminal == getStringValue(T_PERIOD))
		return T_PERIOD;
	else if (terminal == getStringValue(T_NOT))
		return T_NOT;
	else if (terminal == getStringValue(T_WHILE))
		return T_WHILE;
	else if (terminal == getStringValue(T_DO))
		return T_DO;
	else if (terminal == getStringValue(T_IF))
		return T_IF;
	else if (terminal == getStringValue(T_THEN))
		return T_THEN;
	else if (terminal == getStringValue(T_ELSE))
		return T_ELSE;
	else if (terminal == getStringValue(T_FI))
		return T_FI;
	else if (terminal == getStringValue(T_RESERVE))
		return T_RESERVE;
	else if (terminal == getStringValue(T_PROC))
		return T_PROC;
	else if (terminal == getStringValue(T_END))
		return T_END;
	else if (terminal == getStringValue(T_CALL))
		return T_CALL;
	else if (terminal == getStringValue(T_READ))
		return T_READ;
	else if (terminal == getStringValue(T_WRITE))
		return T_WRITE;
	else if (terminal == getStringValue(T_ASSIGN))
		return T_ASSIGN;
	else
		throw invalid_argument("Terminal not found!");
}

vector<string>* TerminalConverter::asStringVector() {
	vector<string>* terminalVector = new vector<string>();
	terminalVector->push_back(getStringValue(T_LEFT_PAREN));
	terminalVector->push_back(getStringValue(T_RIGHT_PAREN));
	terminalVector->push_back(getStringValue(T_COMPARE));
	terminalVector->push_back(getStringValue(T_DIVIDE));
	terminalVector->push_back(getStringValue(T_MULT));
	terminalVector->push_back(getStringValue(T_PLUS));
	terminalVector->push_back(getStringValue(T_MINUS));
	terminalVector->push_back(getStringValue(T_SEMICOLON));
	terminalVector->push_back(getStringValue(T_PERIOD));
	terminalVector->push_back(getStringValue(T_NOT));
	terminalVector->push_back(getStringValue(T_WHILE));
	terminalVector->push_back(getStringValue(T_DO));
	terminalVector->push_back(getStringValue(T_IF));
	terminalVector->push_back(getStringValue(T_THEN));
	terminalVector->push_back(getStringValue(T_ELSE));
	terminalVector->push_back(getStringValue(T_FI));
	terminalVector->push_back(getStringValue(T_RESERVE));
	terminalVector->push_back(getStringValue(T_PROC));
	terminalVector->push_back(getStringValue(T_END));
	terminalVector->push_back(getStringValue(T_CALL));
	terminalVector->push_back(getStringValue(T_READ));
	terminalVector->push_back(getStringValue(T_WRITE));
	terminalVector->push_back(getStringValue(T_ASSIGN));
	return terminalVector;
}

vector<int>* TerminalConverter::asIntVector() {
	vector<int>* terminalVector = new vector<int>();
	terminalVector->push_back(T_LEFT_PAREN);
	terminalVector->push_back(T_RIGHT_PAREN);
	terminalVector->push_back(T_COMPARE);
	terminalVector->push_back(T_DIVIDE);
	terminalVector->push_back(T_MULT);
	terminalVector->push_back(T_PLUS);
	terminalVector->push_back(T_MINUS);
	terminalVector->push_back(T_SEMICOLON);
	terminalVector->push_back(T_PERIOD);
	terminalVector->push_back(T_NOT);
	terminalVector->push_back(T_WHILE);
	terminalVector->push_back(T_DO);
	terminalVector->push_back(T_IF);
	terminalVector->push_back(T_THEN);
	terminalVector->push_back(T_ELSE);
	terminalVector->push_back(T_FI);
	terminalVector->push_back(T_RESERVE);
	terminalVector->push_back(T_PROC);
	terminalVector->push_back(T_END);
	terminalVector->push_back(T_CALL);
	terminalVector->push_back(T_READ);
	terminalVector->push_back(T_WRITE);
	terminalVector->push_back(T_ASSIGN);
	return terminalVector;
}

vector<string>* TerminalConverter::getMatches(const string text) {
	vector<string>* terminalVector = TerminalConverter::asStringVector();
	vector<string>* matches = new vector<string>();
	for (int i = 0; i < terminalVector->size(); i++) {
		if (terminalVector->at(i).substr(0, text.length()) == text)
			matches->push_back(terminalVector->at(i));
	}
	return matches;
}

vector<string>* TerminalConverter::getSpecialStringVector() {
	vector<string>* specialStringVector = new vector<string>();
	specialStringVector->push_back(getStringValue(T_LEFT_PAREN));
	specialStringVector->push_back(getStringValue(T_RIGHT_PAREN));
	specialStringVector->push_back(getStringValue(T_COMPARE));
	specialStringVector->push_back(getStringValue(T_DIVIDE));
	specialStringVector->push_back(getStringValue(T_MULT));
	specialStringVector->push_back(getStringValue(T_PLUS));
	specialStringVector->push_back(getStringValue(T_MINUS));
	specialStringVector->push_back(getStringValue(T_SEMICOLON));
	specialStringVector->push_back(getStringValue(T_PERIOD));
	specialStringVector->push_back(getStringValue(T_NOT));
	return specialStringVector;
}

vector<string>* TerminalConverter::getMatchesSpecialString(const string text) {
	vector<string>* terminalVector = TerminalConverter::getSpecialStringVector();
	vector<string>* matches = new vector<string>();
	for (int i = 0; i < terminalVector->size(); i++) {
		if (terminalVector->at(i).substr(0, text.length()) == text)
			matches->push_back(terminalVector->at(i));
	}
	return matches;
}

#pragma endregion

#pragma region Lexical Analysis

LexicalAnalysis::LexicalAnalysis() {
	this->text = nullptr;
}

LexicalAnalysis::LexicalAnalysis(string* text) {
	this->text = text;
}

LexicalAnalysis::~LexicalAnalysis() {
	delete this->text;
}


void LexicalAnalysis::setText(string* text) {
	this->text = text;
}

string* LexicalAnalysis::getText() const {
	return this->text;
}

vector<string> LexicalAnalysis::getLexemeVector() const {
	vector<string> lexemeVector = vector<string>();
	vector<string>* matches = nullptr;
	string lexeme = "";
	for (int i = 0; i < this->text->length(); i++) {
		vector<string>* specialCharacterMatches = TerminalConverter::getMatchesSpecialString(string(1, text->at(i)));
		if (specialCharacterMatches->size() > 0) {
			if (lexeme.length() > 0)
				lexemeVector.push_back(lexeme);
			lexeme = "";
			string specialLexeme = "";
			for (int o = i; o < this->text->length() && specialCharacterMatches->size() > 0; o++) {
				specialLexeme += text->at(o);
				delete specialCharacterMatches;
				specialCharacterMatches = TerminalConverter::getMatchesSpecialString(specialLexeme);
				if (specialCharacterMatches != nullptr && specialCharacterMatches->size() == 1 && specialLexeme.length() == specialCharacterMatches->at(0).length()) {
					lexemeVector.push_back(specialLexeme);
					specialLexeme = "";
					i = o + 1;
				}
			}
		}
		if (text->at(i) != NEW_LINE && text->at(i) != CARRAGE_RETURN && text->at(i) != SPACE) {
			delete specialCharacterMatches;
			lexeme += text->at(i);
			delete matches;
			matches = TerminalConverter::getMatches(lexeme);
		}
		else {
			if (lexeme.length() > 0)
				lexemeVector.push_back(lexeme);
			lexeme = "";
		}
		if (matches != nullptr && matches->size() == 1 && lexeme.length() == matches->at(0).length()) {
			lexemeVector.push_back(lexeme);
			lexeme = "";
		}
	}
	return lexemeVector;
}

/**
 * Converts a list of tokens to a list of Words
 */
vector<Word> LexicalAnalysis::getWordVector(vector<string> tokenVector) {
	vector<Word> wordVector = vector<Word>();
	for (int i = 0; i < tokenVector.size(); i++) {
		vector<string>* matches = TerminalConverter::getMatches(tokenVector.at(i));
		if (matches->size() == 0)
			wordVector.push_back(Word(T_IDENTIFIER, tokenVector.at(i)));
		else if (matches->size() == 1)
			wordVector.push_back(Word(TerminalConverter::getIntValue(tokenVector.at(i)), tokenVector.at(i)));
		else if (matches->size() > 1)
			throw new invalid_argument("Token has more than one match!");
		delete matches;
	}
	return wordVector;
}

#pragma endregion 