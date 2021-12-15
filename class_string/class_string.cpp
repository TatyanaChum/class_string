#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;//размер строки в байтах
	char* str; //адрес строки динамической памяти

public:
	int get_size() const
	{
		return size;
	}
	const char* get_str() const

	{
		return str;
	}

	char* get_str()

	{
		return str;
	}

	explicit String(int size = 80)

	{
		this->size = size;
		this->str = new char[size] {}; //память, выделяемую для строки обязательно нужно занулить
		cout << "Constructor: \t" << this << endl;
	}

	String(const char str[])

	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}

		cout << "Constructor: \t" << this << endl;
	}

	String(const String& other)

	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor: \t" << this << endl;
	}
	~String()

	{
		delete[]str;
		cout << "Destructor:\t" << this << endl;
	}

	//Operators:

	String& operator = (const String& other)
	{
		if (this == &other) return *this; //проверяем, не является ли this и other одним и тем же обьектом
		delete[] this->str;
		//Deep copy (побитовое копирование)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}

	//methods:

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (size_t i = 0; i < left.get_size(); i++)

		result.get_str()[i] = left.get_str()[i];
	for (size_t i = 0; i < right.get_size(); i++)

		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];

	return result;
}
//char str[] = { 'S','t','r','i','n','g' };
std::ostream& operator << (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();
	cout << str1 << endl;
	String str2(25);//Single - argument constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;

	String str4 = str3; //CopyConstructor
	cout << str4 << endl;

	String str5;
	str5 = str3;// CopyAssignment(operator = )
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK
	String str1 = "Hello";
	String str2 = "World!";
	String str3 = str1 + str2;
	cout << str3 << endl;
}