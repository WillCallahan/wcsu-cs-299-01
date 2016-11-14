#include "MSLLexeme.h"
#include "FileOperations.h"

using namespace edu::wcsu::cs::msl::service;
using namespace std;

int main(int argc, char* argv[]) {
	string text = FileOperations::getFileContents("test.txt");
	LexicalAnalysis lexicalAnalysis = LexicalAnalysis(&text);
	vector<string> lexemeVector = lexicalAnalysis.getLexemeVector();
	cout << "Lexemes:" << endl << endl;
	for (int i = 0; i < lexemeVector.size(); i++)
		cout << lexemeVector.at(i) << endl;
	vector<Word> wordVector = LexicalAnalysis::getWordVector(lexemeVector);
	cout << "Codes:" << endl << endl;
	for (int i = 0; i < wordVector.size(); i++)
		cout << wordVector.at(i).getIdentifier() << endl;
	system("pause");
	return 1;
}