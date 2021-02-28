#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account();
	Account(int i, double bal, double rate);
	int getId(); // ������ �Լ�
	double getBalance();
	double getAnnualInterestRate();
	void setId(int i); // ������ �Լ�
	void setBalance(double bal);
	void setAnnualInterestRate(double rate);
	double getMonthlyInterestRate();
	void withdraw(double amount);
	void deposit(double amount);

private:
	int id;
	double balance;
	double annualInterestRate;
};

#endif