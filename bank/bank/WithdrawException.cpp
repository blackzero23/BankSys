#include "WithdrawException.h"

WithdrawException::WithdrawException(int money) :withdrawMoney(money)
{
}

WithdrawException::~WithdrawException()
{
}

void WithdrawException::ShowExceptionReason()
{
	cout << "��ݾ� : " << withdrawMoney 
		<< "�� �ܾ׺��� �����ϴ�."<<endl;
}
