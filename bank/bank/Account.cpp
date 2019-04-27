#include "Account.h"
#include <iostream>
#include <cstring>
using namespace std;


//����
Account::Account(int newID, char* newCusName) : balance(0)
{
	accID = newID;
	int len = strlen(newCusName);
	cusName = new char[len+1];
	strcpy_s(cusName, len+1, newCusName);
}

Account::Account(int newID, int newMoney, char* newCusName)
{
	accID = newID;
	int len = strlen(newCusName);

	balance = newMoney;
	cusName = new char[len + 1];
	strcpy_s(cusName, len+1 , newCusName);
}

//

//�Ա�
void Account::SetDepositMoney(int newMoney)
{
	balance += newMoney;
}
//��� �ϴ�
void Account::SetWithdrawMoney(int money)
{
	balance -= money;
}


bool Account::CheckAccountID(int checkAccountId)
{
	if (accID == checkAccountId)
		return true;
	else
		return false;
}

int Account::GetAccID() const
{
	return accID;
}

int Account::GetMoney() const
{
	return balance;
}

char* Account::GetAccName() const
{
	return cusName;
}

void Account::ShowAccountInfo() const
{
	cout <<"�� �̸� : " << cusName << endl;
	cout <<"�� ���� : " << accID << endl;
	cout <<"���� �ܾ� : " << balance << endl;	
}

Account::~Account()
{
	cout << "���� �Ҹ�" << endl;
}