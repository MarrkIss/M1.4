#include<iostream>

//#define CONSTRUCTORS_CHECK

class String
{
	unsigned int size;	//Размер строки в Байтах.
	char* str;			//Указатель на строку в динамической памяти.
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//Constructors:
	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstruct:" << this << std::endl;
	}
	String(const char* str)
	{
		this->size = Strlen(str) + 1;
		this->str = new char[size] {};
		//for (int i = 0; str[i]; i++)this->str[i] = str[i];
		for (int i = 0; str[i]; i++)*(this->str + i) = *(str + i);
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "MoveConstructor:" << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "MoveAssignment:" << this << std::endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int index)const
	{
		return str[index];
	}
	char& operator[](int index)
	{
		return str[index];
	}

	//			Methods:
	void print()const
	{
		std::cout << "size:\t" << size << std::endl;
		std::cout << "str:\t" << str << std::endl;
	}

	int Strlen(const char* str)
	{
		int i = 0;
		for (; str[i]; i++);
		return i;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)result.get_str()[i + left.get_size() - 1] = right.get_str()[i];*/
	for (int i = 0; i < left.get_size(); i++)result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)result[i + left.get_size() - 1] = right[i];
	//left.get_str()[3] = '@';
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();
	String str2 = "Hello";
	str2.print();

	String str3 = str2;	//Copy constructor
	str3.print();
	String str4;
	str4 = str2;		//Copy assignment
	str4.print();
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	std::cout << str1 << std::endl;
	/*str1 = str1;
	str1.print();*/
	//String str3 = str1 + str2;	//Move constructor
	//String str3;
	//str3 = str1 + " " + str2;		//Move assignment
	//str3.print();
	//std::cout << str3 << std::endl;
}


//MoveConstructor/MoveAssignment