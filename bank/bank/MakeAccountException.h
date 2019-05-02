#ifndef MAKEACCOUNTEXCEPTION__H_
#define MAKEACCOUNTEXCEPTION__H_

class MakeAccountException :public AccountException
{
private:
	int AccountCnt;
public:
	MakeAccountException(int cnt);

	void ShowExceptionReason();
};


#endif // !
