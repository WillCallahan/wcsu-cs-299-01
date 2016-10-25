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

					class FileOperations {
					private:
						FileOperations();
					public:
						static string getFileContents(string filename);
						static string getFileContents(string filename, int begin);
					};

				}
			}
		}
	}
}