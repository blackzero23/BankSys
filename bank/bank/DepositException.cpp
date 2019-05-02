#include "DepositException.h"

DepositException::DepositException(int money) :depositMoney(money)
{
}

void DepositException::ShowExceptionReason()
{
		cout << "입금액 : " << depositMoney
			<< " 는 입금하실수 없습니다." << endl;
}

DepositException::~DepositException()
{
}
