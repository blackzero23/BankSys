#include"MiniBankingCommonDecl.h"

using namespace std;


//����
Account::Account(int newID, String newCusName) : balance(0)
{
	accID = newID;
	cusName = newCusName;
}

Account::Account(int newID, int newMoney, String newCusName)
{
	accID = newID;
	balance = newMoney;
	cusName = newCusName;
}

Account::Account(Account& ac)
{
	accID = ac.accID;
	balance = ac.balance;
	cusName = ac.cusName;
}

bool Account::checkIsNomalAccout()
{
	return true;
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
	if (balance < money || money< 0)
	{
		WithdrawException expn(money);
		throw expn;
	}

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

String Account::GetAccName() const
{
	return cusName;
}

int Account::GetcusCreditRating()
{
	return 0;
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