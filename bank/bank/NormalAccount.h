#ifndef NORMALACCOUNT__H_
#define NORMALACCOUNT__H_
//보통예금 계좌 entity 클래스
//
#include"MiniBankingCommonDecl.h"

class NomalAccount :public Account
{
protected:
	double interestRate;//이율정보. 초기화 할때 0.03 으로 고정.
public:
	NomalAccount(const int newID,const String newCusName); //초기화
	//입금하다.
	void SetDepositMoney(const int newMoney);
	
	//현재 이율 정보
	double GetinterestRate();

	//계좌 고객 정보 보여주기
	virtual void ShowAccountInfo() const;

	//소멸자
	~NomalAccount();

};



#endif // !
