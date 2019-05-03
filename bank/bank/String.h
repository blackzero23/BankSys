#ifndef STRINGG__H_
#define STRINGG__H_
class String
{
private:
	size_t strLen; //���ڿ� ����
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

	char* str; //���ڿ� �迭 �ּ�.
public:
	//�⺻ ������
	String();
	//�Ű������� �ִ� ������
	String(const char* str);
	String(const int len);
	
	//���� ������
	String(const String& ref);
	

	String& operator=(const String& ref);
	
	//�Ҹ���
	~String();
	
	//���� ������
	//+=
	String& operator+=(const String& ref);
	
	//==
	bool operator==(const String& ref);
	
	//+
	String& operator+(const String& ref);
	


	//��� ������ �����ε�
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