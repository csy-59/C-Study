#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	//파일을 구할 수 없어 윤지님이 유진님께 보내시고 유진님이 제게 보내주신 파일 두가지만 사용합니다... PS. 윤지님 유진님 감사합니다...
	vector<fstream> files;
	files.push_back(fstream("Babynameranking2018.txt", ios::in));
	files.push_back(fstream("Babynameranking2019.txt", ios::in));

	fstream result("BabynamesCombined.txt", ios::out);

	string buff, name;
	int j = 0;

	for (int i = 0;i < files.size();i++) {
		while (!files[i].eof()) {
			//이름 가져오기
			getline(files[i], name, ',');
			j++;
			result << name << " ";
			if (j >= 10) {
				result << '\n';
				j = 0;
			}
			//이름 이외의 것 건너뛰기
			getline(files[i], buff, '\n');
		}
	}

	cout << "Job well done. Check file \"BabynamesCombined.txt\"" << endl;

	return 0;
}