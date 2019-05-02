#ifndef ACOCOUNT__H 
#define ACOCOUNT__H

#include"MiniBankingCommonDecl.h"

const int NAME_LEN = 20;

class Account
{

protected:
	String cusName; //���� �̸�.
	int accID;	//���¹�ȣ
	int balance; //�ܾ�
	//double interestRate;//��������. �ʱ�ȭ �Ҷ� 3.0 ���� ����.

public:

	//���� �ʱ�ȭ

	Account();
	Account(int newID, String newCusName);
	Account(int newID,int newMoney ,String newCusName);

	//���� ������
	Account(Account& ac);

	//���� üũ�Լ�
	virtual bool checkIsNomalAccout();

	//�Ա��ϴ�.
	virtual void SetDepositMoney(int newMoney);
	//����ϴ�.
	void SetWithdrawMoney(int money);
	//���¹�ȣ Ȯ��(��)
	bool CheckAccountID(int checkAccountId);
	//���¹�ȣ ����
	int GetAccID() const;
	//�ܾ� ��ȸ
	int GetMoney() const;
	//���� ���� �̸�
	String GetAccName() const;

	//�ſ���
	virtual int GetcusCreditRating();


	//���� ���� �����ֱ�
	virtual void ShowAccountInfo() const;

	//�Ҹ���
	virtual ~Account();

};


#endif // !
