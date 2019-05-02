#include"MiniBankingCommonDecl.h"

using namespace std;

HighCreditAccount::HighCreditAccount(int newID, int creditRating,
					String newCusName):NomalAccount(newID,newCusName)
	,AddinterestRate(static_cast<double>(creditRating)/100)
{
	cusCreditRating = creditRating;
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
