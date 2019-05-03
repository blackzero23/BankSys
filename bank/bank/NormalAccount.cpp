#include"MiniBankingCommonDecl.h"


using namespace std;

NomalAccount::NomalAccount(const int newID,const String newCusName)
	:Account(newID, newCusName), interestRate(0.03),isNomalAccount(true)
{
}

NomalAccount::NomalAccount(const int newID, const int balance, const String newCusName)
	: Account(newID, newCusName),interestRate(0.03), isNomalAccount(true)
{
	this->balance += balance;
}

bool NomalAccount::checkIsNomalAccout() //üũ ����  �Լ�
{

	return isNomalAccount;
}


void NomalAccount::SetDepositMoney(const int newMoney)
{
	if (newMoney < 0)
	{
		DepositException expn(newMoney);
		throw expn;
	}

	balance += newMoney + static_cast<int>(balance * interestRate);	
}

double NomalAccount::GetinterestRate()
{
	return interestRate;
}

void NomalAccount::ShowAccountInfo() const
{

	cout << "--- ���� ���� �� ---" << endl;
	cout << "�� �̸� : " << GetAccName() << endl;
	cout << "�� ���� : " << GetAccID() << endl;
	cout << "���� �ܾ� : " << GetMoney() << endl;
}

NomalAccount::~NomalAccount()
{
	//cout << "������� �Ҹ�" << endl;
}
