#ifndef NORMALACCOUNT__H_
#define NORMALACCOUNT__H_
//���뿹�� ���� entity Ŭ����
//
#include "Account.h"

class NomalAccount :public Account
{
protected:
	double interestRate;//��������. �ʱ�ȭ �Ҷ� 0.03 ���� ����.
public:
	NomalAccount(int newID, char* newCusName); //�ʱ�ȭ
	//�Ա��ϴ�.
	void SetDepositMoney(int newMoney);
	
	//���� ���� ����
	double GetinterestRate();

	//���� ���� ���� �����ֱ�
	void ShowAccountInfo() const;

	//�Ҹ���
	~NomalAccount();

};



#endif // !