#include "DepositException.h"

DepositException::DepositException(int money) :depositMoney(money)
{
}

void DepositException::ShowExceptionReason()
{
		cout << "�Աݾ� : " << depositMoney
			<< " �� �Ա��ϽǼ� �����ϴ�." << endl;
}

DepositException::~DepositException()
{
}
