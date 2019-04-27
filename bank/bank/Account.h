#ifndef ACOCOUNT__H 
#define ACOCOUNT__H


const int NAME_LEN = 20;

class Account
{

protected:
	char* cusName; //���� �̸�.
	int accID;	//���¹�ȣ
	int balance; //�ܾ�
	//double interestRate;//��������. �ʱ�ȭ �Ҷ� 3.0 ���� ����.

public:

	//���� �ʱ�ȭ

	Account();
	Account(int newID, char* newCusName);
	Account(int newID,int newMoney ,char* newCusName);


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
	char* GetAccName() const;

	//���� ���� �����ֱ�
	virtual void ShowAccountInfo() const;

	//�Ҹ���
	virtual ~Account();

};


#endif // !
