#include"MiniBankingCommonDecl.h"

using namespace std;


//개설
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

/*
Account& Account::operator=(const Account& ac)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	*this = ac;

	return *this;
}
*/
bool Account::checkIsNomalAccout()
{
	return true;
}

//

//입금
void Account::SetDepositMoney(int newMoney)
{
	balance += newMoney;
}
//출금 하다
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
	cout <<"고객 이름 : " << cusName << endl;
	cout <<"고객 계좌 : " << accID << endl;
	cout <<"계좌 잔액 : " << balance << endl;	
}

Account::~Account()
{

}