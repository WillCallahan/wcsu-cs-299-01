#include "FileOperations.h"

using namespace edu::wcsu::cs::msl::service;

#pragma region File Operations

FileOperations::FileOperations() {
	
}

string FileOperations::getFileContents(string filename) {
	return FileOperations::getFileContents(filename, 3); //Skip Byte Order Mark
}

string FileOperations::getFileContents(string filename, int begin) {
	ifstream file;
	string line;
	string output;
	file.open(filename);
	while (!file.eof()) {
		getline(file, line);
		output += line + "\r\n";
	}
	file.close();
	return output.substr(begin);
}

#pragma endregion