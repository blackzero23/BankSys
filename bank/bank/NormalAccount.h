#ifndef NORMALACCOUNT__H_
#define NORMALACCOUNT__H_
//���뿹�� ���� entity Ŭ����
//
#include"MiniBankingCommonDecl.h"

class NomalAccount :public Account
{
protected:
	bool isNomalAccount;
	double interestRate;//��������. �ʱ�ȭ �Ҷ� 0.03 ���� ����.
public:
	NomalAccount(const int newID,const String newCusName); //�ʱ�ȭ
	NomalAccount(const int newID, const int balance ,const String newCusName); //�ʱ�ȭ
														   
	//���� üũ �Լ�
	virtual bool checkIsNomalAccout();
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
