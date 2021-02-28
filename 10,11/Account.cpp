#include <iostream>
#include "Account.h"
using namespace std;

Account::Account() // 扁夯 Account 按眉 积己
{
	id = 0;
	balance = 0;
	annualInterestRate = 0;
}

Account::Account(int i, double bal, double rate) // Account 按眉 积己
{
	id = i;
	balance = bal;
	annualInterestRate = rate;
}

int Account::getId()
{
	return id;
}

double Account::getBalance()
{
	return balance;
}

void Account::setId(int i)
{
	id = i;
}

void Account::setBalance(double bal)
{
	balance = bal;
}

void Account::setAnnualInterestRate(double rate)
{
	annualInterestRate = rate;
}

double Account::getMonthlyInterestRate()
{
	return annualInterestRate / 1200;
}

void Account::withdraw(double amount)
{
	if (amount > balance)
	{
		cout << "\nSorry! There is insufficient balace";
	}
	else
	{
		balance = balance - amount;
	}
}

void Account::deposit(double amount)
{
	balance = balance + amount;
}