#ifndef WITHDRAWEXCEPTION__H_
#define WITHDRAWEXCEPTION__H_

#include "MiniBankingCommonDecl.h"

class WithdrawException :public AccountException
{
private:
	int withdrawMoney;
public:
	WithdrawException(int money);

	~WithdrawException();

	void ShowExceptionReason();
	
};


#endif // !1
