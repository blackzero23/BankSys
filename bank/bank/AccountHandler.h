#ifndef _BANK_H
#define _BANK_H

#include "Account.h"

const int ACCOUNT_MAX = 100; //���� �ִ� ������.
//const int NAME_LEN = 20;

class AccountHandler
{
private:
	Account* accounts[ACCOUNT_MAX]; //���µ�
	//�̷��� ����Ȱ��� �߸��� ���ɼ� �ſ� ����.

	int accCnt; //���� ���� ��.
public:
	//���� �ʱ�ȭ
	AccountHandler();

	explicit AccountHandler(const AccountHandler& bbank); //���� ������
	//���� �Ҹ�

	
	AccountHandler& operator=(const AccountHandler& rhs);//�ܼ� ���� ������.

	~AccountHandler();

	//��ü�޴� ����
	void ShowBankMenu(void);
	//���� ���� �޴� ����
	void ShowAccountKindMenu(void);
	//���°���
	bool MakeAccount(void);
	
	// �Ա�
	void DepositMoney(void);
	// ���
	void WithdrawMoney(void);
	//����������ȸ
	void GetAccountInfoAll(void) const;
	// ���� ��ü
	void TransferAccountMoney(void);

	
	//���� ����
	void DelAccount(void);

};


#endif // !1
