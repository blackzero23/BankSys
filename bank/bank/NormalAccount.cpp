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

	cout << "--- º¸Åë °èÁÂ °í°´ ---" << endl;
	cout << "°í°´ ÀÌ¸§ : " << GetAccName() << endl;
	cout << "°í°´ °èÁÂ : " << GetAccID() << endl;
	cout << "°èÁÂ ÀÜ¾× : " << GetMoney() << endl;
}

NomalAccount::~NomalAccount()
{
	cout << "º¸Åë°èÁÂ ¼Ò¸ê" << endl;
}
