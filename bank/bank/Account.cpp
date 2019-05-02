#include"MiniBankingCommonDecl.h"

using namespace std;


//∞≥º≥
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

//¿‘±›
void Account::SetDepositMoney(int newMoney)
{
	balance += newMoney;
}
//√‚±› «œ¥Ÿ
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
	cout <<"∞Ì∞¥ ¿Ã∏ß : " << cusName << endl;
	cout <<"∞Ì∞¥ ∞Ë¡¬ : " << accID << endl;
	cout <<"∞Ë¡¬ ¿‹æ◊ : " << balance << endl;	
}

Account::~Account()
{
	cout << "∞Ë¡¬ º“∏Í" << endl;
}