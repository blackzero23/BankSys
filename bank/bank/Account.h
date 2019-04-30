#ifndef ACOCOUNT__H 
#define ACOCOUNT__H

#include<string>

const int NAME_LEN = 20;

class Account
{

protected:
	string cusName; //주인 이름.
	int accID;	//계좌번호
	int balance; //잔액
	//double interestRate;//이율정보. 초기화 할때 3.0 으로 고정.

public:

	//계좌 초기화

	Account();
	Account(int newID, string newCusName);
	Account(int newID,int newMoney ,string newCusName);


	//입금하다.
	virtual void SetDepositMoney(int newMoney);
	//출금하다.
	void SetWithdrawMoney(int money);
	//계좌번호 확인(비교)
	bool CheckAccountID(int checkAccountId);
	//계좌번호 정보
	int GetAccID() const;
	//잔액 조회
	int GetMoney() const;
	//계좌 주인 이름
	string GetAccName() const;

	//계좌 정보 보여주기
	virtual void ShowAccountInfo() const;

	//소멸자
	virtual ~Account();

};


#endif // !
