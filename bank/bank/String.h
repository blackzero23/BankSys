#ifndef STRINGG__H_
#define STRINGG__H_
class String
{
private:
	int strLen; //문자열 길이
	char* str; //문자열 배열 주소.
public:
	//기본 생성자
	String();
	//매개변수가 있는 생성자
	String(const char* str);
	String(int len);
	
	//복사 생성자
	String(const String& ref);
	

	String& operator=(const String& ref);
	
	//소멸자
	~String();
	
	//대입 연산자
	//+=
	String& operator+=(const String& ref);
	
	//==
	bool operator==(const String& ref);
	
	//+
	String& operator+(const String& ref);
	


	//출력 연산자 오버로딩
	//<<
	/*char* operator<< (ref)
	{

		return str;
	}*/

	friend ostream& operator<<(ostream& os, const String str);
	friend istream& operator>>(istream& is, String& arr);

	/*String& operator<< (String& (*fp)(String& strr))
	{
		return fp(*this);
	}*/

	//>>
	//void operator>>(String& ref);
	

};


//ostream& operator<<(ostream& os, const String arr);

//istream& operator>>(istream& is, const String arr)
//{
//	char temp[50];
//	is >> temp;
//	strcpy(, temp);
//
//	os << arr.str;
//
//	return os;
//}

#endif