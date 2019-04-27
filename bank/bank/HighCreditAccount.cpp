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
		cout << "½Å¿ëµî±ÞÃâ·Â error" << endl;

	cout << "--- ½Å¿ë½Å·Ú °èÁÂ °í°´ ---" << endl;
	cout << "°í°´ ÀÌ¸§ : " << GetAccName() << endl;
	cout << "°í°´ °èÁÂ : " << GetAccID() << endl;
	cout << "°èÁÂ ÀÜ¾× : " << GetMoney() << endl;
	cout << "°í°´ ½Å¿ë µî±Þ : " << CreditGrade <<endl;


}

HighCreditAccount::~HighCreditAccount()
{
	cout << "½Å¿ë °èÁÂ ¼Ò¸ê" << endl;
}
