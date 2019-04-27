#include <iostream>
#include"AccountHandler.h"

using namespace std;

// 메뉴용 열거자
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE,COPY ,EXIT };



int main(void)
{

	AccountHandler* KoreaBank = new AccountHandler();//ACCOUNT handler
	AccountHandler* CopyKorea = new AccountHandler();

	int choice;

	while (1)
	{
		KoreaBank->ShowBankMenu();
		
		cout << "선택 : ";
		cin >> choice;
		if (cin.fail()) {
			cout << "문자는 포함이 안됩니다." << endl;
			cin.clear(); //오류 스트림초기화
			cin.ignore(256, '\n'); //입력버퍼 비움
			continue;
		}
		cout << endl;

		switch (choice)
		{
		case MAKE:
			if (KoreaBank->MakeAccount())
				cout << "계좌 개설 성공" << endl;
			else
				cout << "계좌 개설 실패" << endl;
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
			cout << "없는 메뉴입니다. 다시 선택해주세요." << endl << endl;
		}

		
	}

	return 0;
}

