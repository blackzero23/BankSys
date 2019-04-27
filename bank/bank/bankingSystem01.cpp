#include <iostream>
#include"AccountHandler.h"

using namespace std;

// �޴��� ������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE,COPY ,EXIT };



int main(void)
{

	AccountHandler* KoreaBank = new AccountHandler();//ACCOUNT handler
	AccountHandler* CopyKorea = new AccountHandler();

	int choice;

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
		case COPY:

			*CopyKorea = *KoreaBank;
			CopyKorea->MakeAccount();
			CopyKorea->GetAccountInfoAll();
			
		break;
		
		case EXIT:		
			
			delete CopyKorea;
			delete KoreaBank;
			return 0;
		default:
			cout << "���� �޴��Դϴ�. �ٽ� �������ּ���." << endl << endl;
		}

		
	}

	return 0;
}

