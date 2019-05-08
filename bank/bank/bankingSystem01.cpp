#include"MiniBankingCommonDecl.h"

using namespace std;

// �޴��� ������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE ,EXIT };



int main(void)
{

	AccountHandler* KoreaBank = new AccountHandler();//ACCOUNT handler

	int choice;
	KoreaBank->InitData(); //�ʱ�ȭ
	while (1)
	{
		KoreaBank->ShowBankMenu();
		
		cout << "���� : ";
		cin >> choice;
		if (cin.fail()) {
			cout << "���ڴ� ������ �ȵ˴ϴ�." << endl;
			cin.clear(); //���� ��Ʈ���ʱ�ȭ
			cin.ignore(256, '\n'); //�Է¹��� ���
			continue;
		}
		cout << endl;

		switch (choice)
		{
		case MAKE:
			if (KoreaBank->MakeAccount())
				cout << "���� ���� ����" << endl;
			else
				cout << "���� ���� ����" << endl;
			break;
		case DEPOSIT:
			KoreaBank->DepositMoney();
			break;
		case WITHDRAW:
			KoreaBank->WithdrawMoney();
			break;
		case INQUIRE:
			KoreaBank->GetAccountInfoAll();
			break;	
		case EXIT:	
			delete KoreaBank;
			return 0;
		default:
			cout << "���� �޴��Դϴ�. �ٽ� �������ּ���." << endl << endl;
		}

		
	}

	return 0;
}

