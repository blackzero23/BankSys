#ifndef HIGHCREDITACCOUNT__H_ 
#define HIGHCREDITACCOUNT__H_


#include"MiniBankingCommonDecl.h"

class HighCreditAccount :public NomalAccount
{
	
protected:
	int cusCreditRating;//�� �ſ� ���
	double AddinterestRate; //�߰� ����
public:
	//�ʱ�ȭ �� �ԱݵǴ� �ݾ׿��� ���� ��� ����.
	HighCreditAccount(int newID, int creditRating, String newCusName);
	HighCreditAccount(int newID, int creditRating,int balance, String newCusName);
	virtual bool checkIsNomalAccout();//���� üũ �Լ�.


	//���� �Ա� �ÿ��� ���� ���.
	// �Ա�
	void SetDepositMoney(int newMoney);

	//�߰�����
	virtual int GetcusCreditRating();

	//���� �� ���� �����ֱ�
	virtual void ShowAccountInfo() const;
	
	//�Ҹ���
	~HighCreditAccount();
};

#endif // !
