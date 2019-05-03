#include"MiniBankingCommonDecl.h"

using namespace std;

HighCreditAccount::HighCreditAccount(int newID, int creditRating,
	String newCusName) :NomalAccount(newID, newCusName)
	, AddinterestRate(static_cast<double>(creditRating) / 100)
{
	isNomalAccount = false;
	cusCreditRating = creditRating;
}

HighCreditAccount::HighCreditAccount(int newID, int creditRating, int balance, String newCusName)
	:NomalAccount(newID, newCusName)
	, AddinterestRate(static_cast<double>(creditRating) / 100)
{
	this->balance += balance;
	isNomalAccount = false;
	cusCreditRating = creditRating;
}



bool HighCreditAccount::checkIsNomalAccout()
{
	return isNomalAccount;
}

void HighCreditAccount::SetDepositMoney(int newMoney)
{
	if (newMoney < 0)
	{
		DepositException expn(newMoney);
		throw expn;
	}

	balance += newMoney + static_cast<int>(balance * (interestRate + AddinterestRate));
}

int HighCreditAccount::GetcusCreditRating()
{
	return cusCreditRating;
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
	//cout << "½Å¿ë °èÁÂ ¼Ò¸ê" << endl;
}
