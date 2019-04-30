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
	HighCreditAccount(int newID, int creditRating, string newCusName);
	
	
	//���� �Ա� �ÿ��� ���� ���.
	// �Ա�
	void SetDepositMoney(int newMoney);

	//���� �� ���� �����ֱ�
	virtual void ShowAccountInfo() const;
	
	//�Ҹ���
	~HighCreditAccount();
};

#endif // !
