#ifndef _BANK_H
#define _BANK_H

#include"MiniBankingCommonDecl.h"

//typedef Point* POINT_PTR;
typedef Account* ACOUNT_PTR;


const int ACCOUNT_MAX = 100; //���� �ִ� ������.
//const int NAME_LEN = 20;

class AccountHandler
{
private:
	ACOUNT_PTR* accounts; //���µ�
	//�̷��� ����Ȱ��� �߸��� ���ɼ� �ſ� ����.

	int accCnt; //���� ���� ��.
public:
	//���� �ʱ�ȭ
	AccountHandler();

	explicit AccountHandler(const AccountHandler& bbank); //���� ������
	//���� �Ҹ�

	
	AccountHandler& operator=(const AccountHandler& rhs);//�ܼ� ���� ������.

	~AccountHandler();


	//������ �����ε�

	ACOUNT_PTR& operator[] (int idx);

	ACOUNT_PTR& operator[] (int idx) const;

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
