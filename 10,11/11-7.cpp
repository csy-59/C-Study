#include <iostream>
#include "Account.h"
using namespace std;

const int ACCOUNT_SIZE = 10;
void checkBalance(Account* account);
void withdraw(Account* account);
void deposit(Account* account);

int main() {
	Account account[ACCOUNT_SIZE];
	for (int i = 0;i < ACCOUNT_SIZE;i++) {
		account[i].setId(i);
		account[i].setBalance(100);
	}

	int getID = 0;
	int getMenu = 0;
	bool isAvailableID = false;
	bool isExit = false;
	bool isAvailableMenu = false;
	bool isPrac = false;

	while (!isPrac) {
		while (!isAvailableID) {
			cout << "Enter an id: ";
			cin >> getID;
			
			if ((getID > -1) && (getID < 10))
				isAvailableID = true;
			else
				cout << "Please enter available ID (0~9)" << endl;
		}

		while (!isExit) {
			cout << "\nMain menu\n1: check balance\n2: withdraw\n3: deposit\n4: exit" << endl;
			while (!isAvailableMenu) {
				cout << "Enter a choice: ";
				cin >> getMenu;

				if ((getMenu > 0) && (getMenu < 5))
					isAvailableMenu = true;
				else
					cout << "Please enter available Menu (1~4)" << endl;
			}

			switch (getMenu)
			{
			case 1: checkBalance(&account[getID]);
				break;
			case 2: withdraw(&account[getID]);
				break;
			case 3: deposit(&account[getID]);
				break;
			case 4: isExit = true;
				break;
			default: cout << "Error" << endl;
				break;
			}
			isAvailableMenu = false;
			getMenu = 0;
		}
		isAvailableID = false;
		isExit = false;
		/*무한으로 작동하는 것을 보고 싶으시면 다음을 주석화 시키세요*/
		//isPrac = true;
	}

	return 0;
}

void checkBalance(Account* account) {
	cout << "The balance is " << account->getBalance() << endl;
}

void withdraw(Account* account) {
	double amount = 0;
	cout << "Enter an amount to withdraw: ";
	cin >> amount;
	account->withdraw(amount);
}

void deposit(Account* account) {
	double amount = 0;
	cout << "Enter an amount to deposit: ";
	cin >> amount;
	account->deposit(amount);
}