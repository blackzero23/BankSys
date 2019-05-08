#include"MiniBankingCommonDecl.h"


using namespace std;

//�ſ��� ������
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//���� �޴��� ������
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
	LoadCusInfoList();//���� ���о��� �� ���� ���� �ε�.
}


void AccountHandler::SaveCusInfoList() //��� �Լ�.
{

	ofstream fp("AccountCusInfo.txt"); //���� ����.

	if (!fp.is_open()) {
		cout << "������ ���� �����ϴ�." << endl;
		//fp.clear();
		//exit(1);
	}
	
	fp << accCnt<<endl;

	for (int i = 0; i < accCnt; i++) {
		
		fp << accounts[i]->checkIsNomalAccout()<<' ' //�븻 üũ
			<< accounts[i]->GetAccID() << ' ' //���� ��ȣ
			<< accounts[i]->GetMoney() << ' ' //�ܾ�
			<< accounts[i]->GetAccName() << ' '; //�̸�
		if (accounts[i]->checkIsNomalAccout())//�븻üũ �븻�̸� �ٿ�� ������
			fp << endl;
		else//�ƴϸ� �ſ��� �����ش�.
			fp << accounts[i]->GetcusCreditRating() << endl;
	}
	
	fp.close();

}

void AccountHandler::LoadCusInfoList() //�����Լ�
{
	ifstream fp("AccountCusInfo.txt");
	
	if (!fp.is_open())
	{
		//cout << "������ ���� �����ϴ�." << endl;
	}
	fp >> accCnt;//���� �ް�
	
	bool checkKindAccount; //�븻 üũ
	int accID; //���¹�ȣ
	int balance;//�ܾ�
	String cusName;//�̸�
	int cusCreditRating;//�߰�����

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


//������ �����ε�
ACOUNT_PTR& AccountHandler::operator[](int idx)
{
	if (idx < 0 || idx >= accCnt)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}

	return  accounts[idx];
}

ACOUNT_PTR AccountHandler::operator[](int idx) const
{
	if (idx < 0 || idx >= accCnt)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}

	return accounts[idx];
}


void AccountHandler::ShowBankMenu(void)
{
	cout << "====== Menu ======" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ��ü���" << endl;	
	cout << "5. ��    ��" << endl;
}

void AccountHandler::ShowAccountKindMenu(void)
{
	cout << "1. ���뿹�� ����" << endl;
	cout << "2. �ſ�ŷڿ��� ����" << endl;
}

bool AccountHandler::MakeAccount(void)
{
	int choice;

	cout << '\n';
	ShowAccountKindMenu();
	cout << '\n' << "���� : ";

	cin >> choice;

	try {
		if (accCnt >= 100)//������ üũ. 100���̻��̸� ���� ����.
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

	int AccountNum;//���� ��ȣ
	String AccountCusName;//�̸�

	cout << "----���� ����----" << endl;
	//���߿��� �ڵ� ���� �������� ������.
	cout << "�����Ͻ� ���¹�ȣ �Է� ���ּ���.";
	cin >> AccountNum;
	if (cin.fail()) {
		cout << "���ڴ� ������ �ȵ˴ϴ�." << endl;
		cin.clear(); //���� ��Ʈ���ʱ�ȭ
		cin.ignore(256, '\n'); //�Է¹��� ���
		return false;
	}

	//���¹�ȣ �ߺ� üũ.
	for (int i = 0; i < accCnt; i++) {
		if (accounts[i]->CheckAccountID(AccountNum)) {
			cout << "���¹�ȣ�� �ߺ� �˴ϴ�." << endl;
			return false;
		}
	}

	cout << "�����Ͻź� �̸��� �Է����ּ���.";
	cin >> AccountCusName;

	//LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2
	switch (choice)
	{
	case NORMAL:
		//������� ����.
		accounts[accCnt] = new NomalAccount(AccountNum, AccountCusName);
		break;

	case CREDIT:
		//�ſ� ��� ���� ����.
		cout << "������ �ſ� ����� �������ּ���. : ";
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
	
	accCnt++;//������ ����.

	SaveCusInfoList(); //���

	return true;

}



//�Ա�
void AccountHandler::DepositMoney(void)
{

	int money;//�Աݾ�
	int AccountNum;//���¹�ȣ


	cout << "[�Ա�]" << endl;
	cout << "���¹�ȣ : "; cin >> AccountNum;

	if (cin.fail()) {
		cout << "���ڴ� ������ �ȵ˴ϴ�." << endl;
		cin.clear(); //���� ��Ʈ���ʱ�ȭ
		cin.ignore(256, '\n'); //�Է¹��� ���
		return;
	}

	for (int i = 0; i < accCnt; i++) {
		if (accounts[i]->CheckAccountID(AccountNum)) {

			cout << "���� �ܾ� ���� : " <<
				accounts[i]->GetMoney() << endl;

			cout << "�Աݾ� : "; cin >> money;
			
			try {
				accounts[i]->SetDepositMoney(money);
			}
			catch(AccountException& expn)
			{
				expn.ShowExceptionReason();
				--i;
				continue;
			}
						
			cout << "�Ա� �Ϸ�" << endl;
			SaveCusInfoList();//���
			return;
		}
	}
	cout << "�߸��� ���������Դϴ�." << endl;

	
}
//���
void AccountHandler::WithdrawMoney(void)
{
	int money;//�Աݾ�
	int AccountNum;//���¹�ȣ

	cout << "[���]" << endl;
	cout << "���¹�ȣ : "; cin >> AccountNum;

	if (cin.fail()) {
		cout << "���ڴ� ������ �ȵ˴ϴ�." << endl;
		cin.clear(); //���� ��Ʈ���ʱ�ȭ
		cin.ignore(256, '\n'); //�Է¹��� ���
		return;
	}

	for (int i = 0; i < accCnt; i++) {
		if (accounts[i]->CheckAccountID(AccountNum)) {
			cout << "���� �ܾ� ���� : " <<
				accounts[i]->GetMoney() << endl;

			cout << "��� �� : "; cin >> money;
			try
			{
				accounts[i]->SetWithdrawMoney(money);
			}
			catch (AccountException& expn)
			{
				cout << "�ܾ��� �����մϴ�." << endl << endl;
				--i;
				continue;
			}
			cout << "��� �Ϸ�" << endl;
			SaveCusInfoList();//���
			return;
		}
		else
			cout << "�߸��� ���������Դϴ�." << endl;
	}

	
}

//��ü �� ���� ���� ��ȸ 
void AccountHandler::GetAccountInfoAll(void) const
{
	cout << "---- ��ü �� ���� ----" << endl;
	for (int i = 0; i < accCnt; i++) {
		accounts[i]->ShowAccountInfo();
		cout << "\n";
	}

	//cout << sizeof(accounts) << endl;
}


//���� ��ü.
void AccountHandler::TransferAccountMoney(void)
{
}


//���� ����.
void AccountHandler::DelAccount(void)
{
}

