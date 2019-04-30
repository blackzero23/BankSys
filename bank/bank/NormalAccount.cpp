#include"MiniBankingCommonDecl.h"


using namespace std;

NomalAccount::NomalAccount(int newID, string newCusName)
	:Account(newID, newCusName), interestRate(0.03)
{
}


void NomalAccount::SetDepositMoney(int newMoney)
{
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
