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
	//복사생성자
	AccountTemplate(const AccountTemplate& arr) {}
	//대입연산자
	//AccountTemplate& operator=(const AccountTemplate& arr);
	
public:
	AccountTemplate();

	AccountTemplate(int len);

	T& operator[](int idx);//데이터 수정.


	//출력
	T operator[](int idx) const; 

	//저장된 요소 개수.
	int getArrLen() const;
	
	//소멸자
	~AccountTemplate();


};

//생성자
template<typename T>
AccountTemplate<T>::AccountTemplate() :arrlen(0)
{
	arr = new T[50];
}

//생성자
template<typename T>
AccountTemplate<T>::AccountTemplate(int len) : arrlen(len)
{
	arr = new T[len];
}

//[]연산자 오버로딩
template<typename T>
T& AccountTemplate<T>:: operator[](int idx)
{
	if (idx < 0 || idx >= 50)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}
	return arr[idx];
}



//const []연산자 오버로딩
template<typename T>
T AccountTemplate<T>:: operator[](int idx) const
{
	if (idx < 0 || idx >= 50)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
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

//소멸자.
template<typename T>
AccountTemplate<T>::~AccountTemplate()
{
	delete[] arr;
}



#endif // !

