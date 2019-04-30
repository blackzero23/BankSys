#include"MiniBankingCommonDecl.h"

using namespace std;


//����
Account::Account(int newID, string newCusName) : balance(0)
{
	accID = newID;
	cusName = newCusName;
}

Account::Account(int newID, int newMoney, string newCusName)
{
	accID = newID;
	cusName = newCusName;
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

string Account::GetAccName() const
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