#include"MiniBankingCommonDecl.h"
String::String()
{
	strLen = 0;
	str = NULL;
}

String::String(const char* str)
{
	strLen = strlen(str) + 1;
	this->str = new char[strLen];
	strcpy_s(this->str, strLen, str);
}
String::String(const int len)
{
	strLen = len;

	str = new char[strLen];
}


String::String(const String& ref)
{
	strLen = strlen(ref.str)+1;
	this->str = new char[strLen];
	strcpy_s(this->str, strLen, ref.str);
}


String& String::operator=(const String& ref)
{
	strLen = strlen(ref.str) + 1;
	this->str = new char[strLen];
	strcpy_s(this->str, strLen, ref.str);

	return *this;
}

//소멸자
String::~String()
{
	delete[] str;
}
//대입 연산자
//+=
String& String::operator+=(const String& ref)
{
	size_t catLen = strlen(str) + strlen(ref.str) + 1;
	char* temp = new char[catLen];
	strcpy_s(temp, strlen(str) + 1, str);
	strcat_s(temp, catLen, ref.str);

	delete[] str;
	str = new char[catLen];

	strcpy_s(str, catLen, temp);


	return *this;
}
//==
bool String::operator==(const String& ref)
{
	if (!strcmp(str, ref.str))
		return true;
	else
		return false;
}
//+
String& String::operator+(const String& ref)
{
	size_t catLen = strlen(str) + strlen(ref.str) + 1;
	char* temp = new char[catLen];
	strcpy_s(temp, strlen(str) + 1, str);
	strcat_s(temp, catLen, ref.str);

	String* testString = new String(temp);

	delete[] temp;

	return *testString;
}


//출력 연산자 오버로딩
//<<
/*char* operator<< (ref)
{

	return str;
}*/



/*String& operator<< (String& (*fp)(String& strr))
{
	return fp(*this);
}*/

//>>
//void String::operator>>(String& ref)
//{
//	scanf_s("%s", str, sizeof(str));
//}

ostream& operator<<(ostream& os, const String str)
{
	os << str.str;
	return os;
	// TODO: 여기에 반환 구문을 삽입합니다.
}



istream& operator>>(istream& is, String& arr)
{
		char* temp= new char[1000];
		is >> temp;
		arr = String(temp);
		//strcpy_s(arr.str,1000,temp);
	
		delete[] temp;
	
		return is;
}
