#ifndef STRINGG__H_
#define STRINGG__H_
class String
{
private:
	size_t strLen; //문자열 길이
	/*
	// C4267.cpp
	// compile by using: cl /W4 C4267.cpp
	void Func1(short) {}
	void Func2(int) {}
	void Func3(long) {}
	void Func4(size_t) {}

	int main() {
	size_t bufferSize = 10;
	Func1(bufferSize);   // C4267 for all platforms
	Func2(bufferSize);   // C4267 only for 64-bit platforms
	Func3(bufferSize);   // C4267 only for 64-bit platforms
	Func4(bufferSize);   // OK for all platforms
	*/

	char* str; //문자열 배열 주소.
public:
	//기본 생성자
	String();
	//매개변수가 있는 생성자
	String(const char* str);
	String(const int len);
	
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