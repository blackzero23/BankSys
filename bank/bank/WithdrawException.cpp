#include "WithdrawException.h"

WithdrawException::WithdrawException(int money) :withdrawMoney(money)
{
}

WithdrawException::~WithdrawException()
{
}

void WithdrawException::ShowExceptionReason()
{
	cout << "출금액 : " << withdrawMoney 
		<< "이 잔액보다 많습니다."<<endl;
}
