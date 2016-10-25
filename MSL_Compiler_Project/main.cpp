#include "MSLLexeme.h"
#include "FileOperations.h"

using namespace edu::wcsu::cs::msl;
using namespace edu::wcsu::cs::msl::service;
using namespace std;

int main(int argc, char* argv[]) {
	string text = FileOperations::getFileContents("test.txt");
	LexicalAnalysis lexicalAnalysis = LexicalAnalysis(&text);
	vector<string> lexemeVector = lexicalAnalysis.getLexemeVector();
	for (int i = 0; i < lexemeVector.size(); i++)
		cout << lexemeVector.at(i) << endl;
	system("pause");
}