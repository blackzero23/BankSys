#include"MiniBankingCommonDecl.h"


MakeAccountException::MakeAccountException(int cnt) 
	:AccountCnt(cnt)
{}

void MakeAccountException::ShowExceptionReason()
{
	cout<<"���� ���� �� : " <<AccountCnt<<
		"�̻� ����� �����ϴ�."<<endl;
}
