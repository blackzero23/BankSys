#include "HighCreditAccount.h"
#include<iostream>

using namespace std;

HighCreditAccount::HighCreditAccount(int newID, int creditRating,
					char* newCusName):NomalAccount(newID,newCusName)
	,AddinterestRate((double)creditRating/100)
{
	cusCreditRating = creditRating;
}

void HighCreditAccount::SetDepositMoney(int newMoney)
{
	balance += newMoney + (balance * (interestRate + AddinterestRate));
}

void HighCreditAccount::ShowAccountInfo() const
{

	char CreditGrade;
	
	if (cusCreditRating == 7)
		CreditGrade = 'A';
	else if (cusCreditRating == 4)
		CreditGrade = 'B';
	else if (cusCreditRating == 2)
		CreditGrade = 'C';
	else
		cout << "�ſ������ error" << endl;

	cout << "--- �ſ�ŷ� ���� �� ---" << endl;
	cout << "�� �̸� : " << GetAccName() << endl;
	cout << "�� ���� : " << GetAccID() << endl;
	cout << "���� �ܾ� : " << GetMoney() << endl;
	cout << "�� �ſ� ��� : " << CreditGrade <<endl;


}

HighCreditAccount::~HighCreditAccount()
{
	cout << "�ſ� ���� �Ҹ�" << endl;
}
