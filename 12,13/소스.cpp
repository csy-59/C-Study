#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int fileNum = 0;
	vector<string> fileNames;
	string buff;

	cout << "Enter the number of source files: ";
	cin >> fileNum;
	for (int i = 0;i < fileNum;i++) {
		cout << "Enter a source file: ";
		cin >> buff;
		fileNames.push_back(buff);
	}

	cout << "Enter a target file: ";
	cin >> buff;
	fileNames.push_back(buff);

	vector<fstream> inputFiles;

	for (int i = 0;i < fileNum;i++) {
		inputFiles.push_back(fstream(fileNames[i].c_str()));
		//입력한 파일이 존재하지 않을시 종료
		if (inputFiles[i].fail()) {
			cout << "File " << fileNames[i] << " does not exist" << endl;
			cout << "Exist program..." << endl;
			return 0;
		}
	}

	fstream combinedFile;
	combinedFile.open(fileNames[fileNum].c_str());
	if (combinedFile.fail()) {
		cout << "File " << fileNames[fileNum] << " does not exist" << endl;
		cout << "Exist program..." << endl;
		return 0;
	}

	//병합 진행
	for (int i = 0;i < fileNum;i++) {
		char ch = inputFiles[i].get();
		while (!inputFiles[i].eof()) {
			combinedFile.put(ch);
			ch = inputFiles[i].get();
		}
	}

	cout << "Combine Done" << endl;

	for (int i = 0;i < fileNum;i++) {
		inputFiles[i].close();
	}
	combinedFile.close();

	return 0;
}