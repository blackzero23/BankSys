#include"MiniBankingCommonDecl.h"


using namespace std;

//신용등급 열거자
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//계좌 메뉴용 열거자
enum { NORMAL = 1, CREDIT = 2 };

AccountHandler::AccountHandler() :accCnt(0)
{
//	accounts = new AccountTemplete[50];
}

AccountHandler::AccountHandler(int len) :accCnt(len)
{
	//accounts = new ACOUNT_PTR[len];
}


void AccountHandler::InitData()
{
	LoadCusInfoList();//계좌 구분없이 총 계좌 정보 로드.
}


void AccountHandler::SaveCusInfoList() //백업 함수.
{

	ofstream fp("AccountCusInfo.txt"); //새로 쓴다.

	if (!fp.is_open()) {
		cout << "파일을 열수 없습니다." << endl;
		//fp.clear();
		//exit(1);
	}
	
	fp << accCnt<<endl;

	for (int i = 0; i < accCnt; i++) {
		
		fp << accounts[i]->checkIsNomalAccout()<<' ' //노말 체크
			<< accounts[i]->GetAccID() << ' ' //계좌 번호
			<< accounts[i]->GetMoney() << ' ' //잔액
			<< accounts[i]->GetAccName() << ' '; //이름
		if (accounts[i]->checkIsNomalAccout())//노말체크 노말이면 뛰우고 끝내고
			fp << endl;
		else//아니면 신용등급 적어준다.
			fp << accounts[i]->GetcusCreditRating() << endl;
	}
	
	fp.close();

}

void AccountHandler::LoadCusInfoList() //복구함수
{
	ifstream fp("AccountCusInfo.txt");
	
	if (!fp.is_open())
	{
		//cout << "파일을 열수 없습니다." << endl;
	}
	fp >> accCnt;//갯수 받고
	
	bool checkKindAccount; //노말 체크
	int accID; //계좌번호
	int balance;//잔액
	String cusName;//이름
	int cusCreditRating;//추가이율

	//NomalAccount::NomalAccount(const int newID, const int balance, const String newCusName)
	//HighCreditAccount(int newID, int creditRating,int balance, String newCusName);
	
	for (int i = 0; i < accCnt; i++)
	{
		fp >> checkKindAccount
		   >> accID
		   >> balance
		   >> cusName;
		if (checkKindAccount) {
			accounts[i] = new NomalAccount(accID, balance, cusName);
		}
		else {
			fp >> cusCreditRating;
			accounts[i] = new HighCreditAccount(accID, cusCreditRating, balance, cusName);
		}
	}

	fp.close();
}




AccountHandler::~AccountHandler()
{
	if (accCnt != 0)
		for (int i = 0; i < accCnt; i++)
			delete accounts[i];
}


//연산자 오버로딩
ACOUNT_PTR& AccountHandler::operator[](int idx)
{
	if (idx < 0 || idx >= accCnt)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}

	return  accounts[idx];
}

ACOUNT_PTR AccountHandler::operator[](int idx) const
{
	if (idx < 0 || idx >= accCnt)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}

	return accounts[idx];
}


void AccountHandler::ShowBankMenu(void)
{
	cout << "====== Menu ======" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 전체출력" << endl;	
	cout << "5. 종    료" << endl;
}

void AccountHandler::ShowAccountKindMenu(void)
{
	cout << "1. 보통예금 계좌" << endl;
	cout << "2. 신용신뢰예금 계좌" << endl;
}

bool AccountHandler::MakeAccount(void)
{
	int choice;

	cout << '\n';
	ShowAccountKindMenu();
	cout << '\n' << "선택 : ";

	cin >> choice;

	try {
		if (accCnt >= 100)//개설수 체크. 100개이상이면 개설 못함.
		{
			MakeAccountException expn(accCnt);
			throw expn;
		}
			 
	}
	catch(AccountException& expn)
	{
		expn.ShowExceptionReason();
		return false;
	}

	int AccountNum;//계좌 번호
	String AccountCusName;//이름

	cout << "----계좌 개설----" << endl;
	//나중에는 자동 랜덤 생성으로 만들어보자.
	cout << "개설하실 계좌번호 입력 해주세요.";
	cin >> AccountNum;
	if (cin.fail()) {
		cout << "문자는 포함이 안됩니다." << endl;
		cin.clear(); //오류 스트림초기화
		cin.ignore(256, '\n'); //입력버퍼 비움
		return false;
	}

	//계좌번호 중복 체크.
	for (int i = 0; i < accCnt; i++) {
		if (accounts[i]->CheckAccountID(AccountNum)) {
			cout << "계좌번호가 중복 됩니다." << endl;
			return false;
		}
	}

	cout << "개설하신분 이름을 입력해주세요.";
	cin >> AccountCusName;

	//LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2
	switch (choice)
	{
	case NORMAL:
		//보통계좌 개설.
		accounts[accCnt] = new NomalAccount(AccountNum, AccountCusName);
		break;

	case CREDIT:
		//신용 등급 계좌 개설.
		cout << "고객님의 신용 등급을 선택해주세요. : ";
		cout << "\n 1.A \n 2.B \n 3.C \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			accounts[accCnt] = new HighCreditAccount(AccountNum, LEVEL_A, AccountCusName);
			break;
		case 2:
			accounts[accCnt] = new HighCreditAccount(AccountNum, LEVEL_B, AccountCusName);
			break;
		case 3:
			accounts[accCnt] = new HighCreditAccount(AccountNum, LEVEL_C, AccountCusName);
			break;
		default:
			break;
		}


				
		break;
	default:
		break;
	}
	
	accCnt++;//개설수 증가.

	SaveCusInfoList(); //백업

	return true;

}



//입금
void AccountHandler::DepositMoney(void)
{

	int money;//입금액
	int AccountNum;//계좌번호


	cout << "[입금]" << endl;
	cout << "계좌번호 : "; cin >> AccountNum;

	if (cin.fail()) {
		cout << "문자는 포함이 안됩니다." << endl;
		cin.clear(); //오류 스트림초기화
		cin.ignore(256, '\n'); //입력버퍼 비움
		return;
	}

	for (int i = 0; i < accCnt; i++) {
		if (accounts[i]->CheckAccountID(AccountNum)) {

			cout << "현제 잔액 정보 : " <<
				accounts[i]->GetMoney() << endl;

			cout << "입금액 : "; cin >> money;
			
			try {
				accounts[i]->SetDepositMoney(money);
			}
			catch(AccountException& expn)
			{
				expn.ShowExceptionReason();
				--i;
				continue;
			}
						
			cout << "입금 완료" << endl;
			SaveCusInfoList();//백업
			return;
		}
	}
	cout << "잘못된 계좌정보입니다." << endl;

	
}
//출금
void AccountHandler::WithdrawMoney(void)
{
	int money;//입금액
	int AccountNum;//계좌번호

	cout << "[출금]" << endl;
	cout << "계좌번호 : "; cin >> AccountNum;

	if (cin.fail()) {
		cout << "문자는 포함이 안됩니다." << endl;
		cin.clear(); //오류 스트림초기화
		cin.ignore(256, '\n'); //입력버퍼 비움
		return;
	}

	for (int i = 0; i < accCnt; i++) {
		if (accounts[i]->CheckAccountID(AccountNum)) {
			cout << "현제 잔액 정보 : " <<
				accounts[i]->GetMoney() << endl;

			cout << "출금 액 : "; cin >> money;
			try
			{
				accounts[i]->SetWithdrawMoney(money);
			}
			catch (AccountException& expn)
			{
				cout << "잔액이 부족합니다." << endl << endl;
				--i;
				continue;
			}
			cout << "출금 완료" << endl;
			SaveCusInfoList();//백업
			return;
		}
		else
			cout << "잘못된 계좌정보입니다." << endl;
	}

	
}

//전체 고객 계좌 정보 조회 
void AccountHandler::GetAccountInfoAll(void) const
{
	cout << "---- 전체 고객 정보 ----" << endl;
	for (int i = 0; i < accCnt; i++) {
		accounts[i]->ShowAccountInfo();
		cout << "\n";
	}

	//cout << sizeof(accounts) << endl;
}


//계좌 이체.
void AccountHandler::TransferAccountMoney(void)
{
}


//계좌 삭제.
void AccountHandler::DelAccount(void)
{
}

