#include"MiniBankingCommonDecl.h"


MakeAccountException::MakeAccountException(int cnt) 
	:AccountCnt(cnt)
{}

void MakeAccountException::ShowExceptionReason()
{
	cout<<"허용된 계좌 수 : " <<AccountCnt<<
		"이상 만들수 없습니다."<<endl;
}
