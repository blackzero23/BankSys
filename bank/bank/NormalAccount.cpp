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

bool NomalAccount::checkIsNomalAccout() //Ã¼Å© Á¾·ù  ÇÔ¼ö
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

	cout << "--- º¸Åë °èÁÂ °í°´ ---" << endl;
	cout << "°í°´ ÀÌ¸§ : " << GetAccName() << endl;
	cout << "°í°´ °èÁÂ : " << GetAccID() << endl;
	cout << "°èÁÂ ÀÜ¾× : " << GetMoney() << endl;
}

NomalAccount::~NomalAccount()
{
	//cout << "º¸Åë°èÁÂ ¼Ò¸ê" << endl;
}
