#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	//������ ���� �� ���� �������� �����Բ� �����ð� �������� ���� �����ֽ� ���� �ΰ����� ����մϴ�... PS. ������ ������ �����մϴ�...
	vector<fstream> files;
	files.push_back(fstream("Babynameranking2018.txt", ios::in));
	files.push_back(fstream("Babynameranking2019.txt", ios::in));

	fstream result("BabynamesCombined.txt", ios::out);

	string buff, name;
	int j = 0;

	for (int i = 0;i < files.size();i++) {
		while (!files[i].eof()) {
			//�̸� ��������
			getline(files[i], name, ',');
			j++;
			result << name << " ";
			if (j >= 10) {
				result << '\n';
				j = 0;
			}
			//�̸� �̿��� �� �ǳʶٱ�
			getline(files[i], buff, '\n');
		}
	}

	cout << "Job well done. Check file \"BabynamesCombined.txt\"" << endl;

	return 0;
}