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

	cout << "--- º¸Åë °èÁÂ °í°´ ---" << endl;
	cout << "°í°´ ÀÌ¸§ : " << GetAccName() << endl;
	cout << "°í°´ °èÁÂ : " << GetAccID() << endl;
	cout << "°èÁÂ ÀÜ¾× : " << GetMoney() << endl;
}

NomalAccount::~NomalAccount()
{
	cout << "º¸Åë°èÁÂ ¼Ò¸ê" << endl;
}
