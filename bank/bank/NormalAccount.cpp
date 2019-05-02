#include"MiniBankingCommonDecl.h"


using namespace std;

NomalAccount::NomalAccount(const int newID,const String newCusName)
	:Account(newID, newCusName), interestRate(0.03)
{
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
	cout << "������� �Ҹ�" << endl;
}
