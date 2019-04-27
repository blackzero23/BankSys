#include "Account.h"
#include <iostream>
#include <cstring>
using namespace std;


//∞≥º≥
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

//¿‘±›
void Account::SetDepositMoney(int newMoney)
{
	balance += newMoney;
}
//√‚±› «œ¥Ÿ
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
	cout <<"∞Ì∞¥ ¿Ã∏ß : " << cusName << endl;
	cout <<"∞Ì∞¥ ∞Ë¡¬ : " << accID << endl;
	cout <<"∞Ë¡¬ ¿‹æ◊ : " << balance << endl;	
}

Account::~Account()
{
	cout << "∞Ë¡¬ º“∏Í" << endl;
}