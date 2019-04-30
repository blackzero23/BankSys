#include"MiniBankingCommonDecl.h"


using namespace std;

//�ſ��� ������
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//���� �޴��� ������
enum { NORMAL = 1, CREDIT = 2 };

AccountHandler::AccountHandler() :accCnt(0)
{
}



AccountHandler::AccountHandler(const AccountHandler& rhs) : accCnt(rhs.accCnt)//���� ������.
{
	if (rhs.accCnt != 0) {
		for (int i = 0; i < rhs.accCnt; i++) {
			this->accounts[i] = new Account(
				rhs.accounts[i]->GetAccID()
				, rhs.accounts[i]->GetMoney()
				, rhs.accounts[i]->GetAccName());
		}

	}
}


AccountHandler& AccountHandler::operator=(const AccountHandler& rhs)
{

	this->accCnt = rhs.accCnt;

	if (rhs.accCnt != 0) {
		for (int i = 0; i < rhs.accCnt; i++) {
			this->accounts[i] = new Account(
				rhs.accounts[i]->GetAccID()
				, rhs.accounts[i]->GetMoney()
				, rhs.accounts[i]->GetAccName());
		}
	}


	return *this;
}

AccountHandler::~AccountHandler()
{
	if (accCnt != 0)
		for (int i = 0; i < accCnt; i++)
			delete accounts[i];
}


void AccountHandler::ShowBankMenu(void)
{
	cout << "====== Menu ======" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. ��ü���" << endl;
	cout << "5. ���� ������ Ȯ��" << endl;
	cout << "6. ��    ��" << endl;
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


	if (accCnt >= 100)		 //������ üũ
		return false; //100���̻��̸� ���� ����.

	int AccountNum;//���� ��ȣ
	char AccountCusName[NAME_LEN];//�̸�

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
			accounts[i]->SetDepositMoney(money);
			cout << "�Ա� �Ϸ�" << endl;
			return;
		}
		else
			cout << "�߸��� ���������Դϴ�." << endl;
	}

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

			if (accounts[i]->GetMoney() < money) {
				cout << "�ܾ��� �����մϴ�." << endl << endl;
				return;
			}

			accounts[i]->SetWithdrawMoney(money);
			cout << "��� �Ϸ�" << endl;
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
}


//���� ��ü.
void AccountHandler::TransferAccountMoney(void)
{
}


//���� ����.
void AccountHandler::DelAccount(void)
{
}

