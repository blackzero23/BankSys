#ifndef NORMALACCOUNT__H_
#define NORMALACCOUNT__H_
//���뿹�� ���� entity Ŭ����
//
#include"MiniBankingCommonDecl.h"

class NomalAccount :public Account
{
protected:
	double interestRate;//��������. �ʱ�ȭ �Ҷ� 0.03 ���� ����.
public:
	NomalAccount(const int newID,const String newCusName); //�ʱ�ȭ
	//�Ա��ϴ�.
	void SetDepositMoney(const int newMoney);
	
	//���� ���� ����
	double GetinterestRate();

	//���� �� ���� �����ֱ�
	virtual void ShowAccountInfo() const;

	//�Ҹ���
	~NomalAccount();

};



#endif // !
