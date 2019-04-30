#ifndef ACOCOUNT__H 
#define ACOCOUNT__H

#include<string>

const int NAME_LEN = 20;

class Account
{

protected:
	string cusName; //���� �̸�.
	int accID;	//���¹�ȣ
	int balance; //�ܾ�
	//double interestRate;//��������. �ʱ�ȭ �Ҷ� 3.0 ���� ����.

public:

	//���� �ʱ�ȭ

	Account();
	Account(int newID, string newCusName);
	Account(int newID,int newMoney ,string newCusName);


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
	string GetAccName() const;

	//���� ���� �����ֱ�
	virtual void ShowAccountInfo() const;

	//�Ҹ���
	virtual ~Account();

};


#endif // !
