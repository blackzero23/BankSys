#ifndef HIGHCREDITACCOUNT__H_ 
#define HIGHCREDITACCOUNT__H_


#include"MiniBankingCommonDecl.h"

class HighCreditAccount :public NomalAccount
{
	
protected:
	int cusCreditRating;//고객 신용 등급
	double AddinterestRate; //추가 이율
public:
	//초기화 시 입금되는 금액에는 이율 계산 안함.
	HighCreditAccount(int newID, int creditRating, char* newCusName);
	
	
	//이후 입금 시에만 이율 계산.
	// 입금
	void SetDepositMoney(int newMoney);

	//계좌 고객 정보 보여주기
	void ShowAccountInfo() const;
	
	//소멸자
	~HighCreditAccount();
};

#endif // !
