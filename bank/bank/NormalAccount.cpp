#include <iostream>
#include "NormalAccount.h"


using namespace std;

NomalAccount::NomalAccount(int newID, char* newCusName)
	:Account(newID, newCusName), interestRate(0.03)
{
}

void NomalAccount::SetDepositMoney(int newMoney)
{
	balance += newMoney + (balance * interestRate);	
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
