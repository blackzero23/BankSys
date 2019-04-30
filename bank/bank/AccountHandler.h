#ifndef _BANK_H
#define _BANK_H

#include"MiniBankingCommonDecl.h"

//typedef Point* POINT_PTR;
typedef Account* ACOUNT_PTR;


const int ACCOUNT_MAX = 100; //계좌 최대 개설수.
//const int NAME_LEN = 20;

class AccountHandler
{
private:
	ACOUNT_PTR* accounts; //계좌들
	//이렇게 선언된것이 잘못될 가능성 매우 높음.

	int accCnt; //계좌 개설 수.
public:
	//은행 초기화
	AccountHandler();

	explicit AccountHandler(const AccountHandler& bbank); //복사 생성자
	//은행 소멸

	
	AccountHandler& operator=(const AccountHandler& rhs);//단순 대입 연산자.

	~AccountHandler();


	//연산자 오버로딩

	ACOUNT_PTR& operator[] (int idx);

	ACOUNT_PTR& operator[] (int idx) const;

	//전체메뉴 오픈
	void ShowBankMenu(void);
	//계좌 종류 메뉴 오픈
	void ShowAccountKindMenu(void);
	//계좌개설
	bool MakeAccount(void);
	
	// 입금
	void DepositMoney(void);
	// 출금
	void WithdrawMoney(void);
	//계좌정보조회
	void GetAccountInfoAll(void) const;
	// 계좌 이체
	void TransferAccountMoney(void);

	
	//계좌 삭제
	void DelAccount(void);

};


#endif // !1
