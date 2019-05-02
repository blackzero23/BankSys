#ifndef DEPOSITEXCEPTION__H_ 
#define DEPOSITEXCEPTION__H_

#include"MiniBankingCommonDecl.h"

class DepositException :public AccountException
{
private:
	int depositMoney;
public:
	DepositException(int money);

	void ShowExceptionReason();
	
	~DepositException();
};


#endif // !
