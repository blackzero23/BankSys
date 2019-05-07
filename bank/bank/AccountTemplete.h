#ifndef AccountTemplate__H_
#define AccountTemplate__H_

#include"MiniBankingCommonDecl.h"
using namespace std;

template <typename T>
class AccountTemplate
{
private:
	T* arr;
	int arrlen;
	//���������
	AccountTemplate(const AccountTemplate& arr) {}
	//���Կ�����
	//AccountTemplate& operator=(const AccountTemplate& arr);
	
public:
	AccountTemplate();

	AccountTemplate(int len);

	T& operator[](int idx);//������ ����.


	//���
	T operator[](int idx) const; 

	//����� ��� ����.
	int getArrLen() const;
	
	//�Ҹ���
	~AccountTemplate();


};

//������
template<typename T>
AccountTemplate<T>::AccountTemplate() :arrlen(0)
{
	arr = new T[50];
}

//������
template<typename T>
AccountTemplate<T>::AccountTemplate(int len) : arrlen(len)
{
	arr = new T[len];
}

//[]������ �����ε�
template<typename T>
T& AccountTemplate<T>:: operator[](int idx)
{
	if (idx < 0 || idx >= 50)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}
	return arr[idx];
}



//const []������ �����ε�
template<typename T>
T AccountTemplate<T>:: operator[](int idx) const
{
	if (idx < 0 || idx >= 50)
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}

	return arr[idx];
}


//GetArrlen()

template<typename T>
int AccountTemplate<T>::getArrLen() const
{
	return arrlen;
}

//�Ҹ���.
template<typename T>
AccountTemplate<T>::~AccountTemplate()
{
	delete[] arr;
}



#endif // !

