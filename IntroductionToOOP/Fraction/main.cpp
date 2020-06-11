#include<iostream>

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define INPUT_OUTPUT_CHECK
#define TYPE_CONVERSIONS

class Fraction
{
	//Описывает простую дробь.
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator != 0)
		{
			this->denominator = denominator;
		}
		else
		{
			this->denominator = 1;
		}
	}

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "DefaultConstruct:\t" << this << std::endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		std::cout << "SingleArgumentConstructor:\t" << this << std::endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator ? denominator : 1;
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator ? denominator : 1;
		/*
			condition ? expression1 : expression2;
		*/
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Fraction(const Fraction& other)
	{
		//*this = other;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	Fraction& operator*=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->to_proper();
	}

	/*Fraction operator*(Fraction right) const
	{
		Fraction left = *this;
		left.to_improper();
		right.to_improper();
		Fraction result;
		result.numerator = left.numerator*right.numerator;
		result.denominator = left.denominator*right.denominator;
		result.to_proper();
		return result;
	}*/

	//		Increment/Decrement
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction buffer = *this;
		this->integer++;
		return buffer;
	}

	//		type-cast operators:
	explicit operator int() const
	{
		return integer;
	}
	operator double() const
	{
		//Из простой дроби делает десятичную дробь.
		return integer + (double)numerator / denominator;
	}

	//		Methods:
	Fraction& print()
	{
		if (integer)std::cout << integer;
		if (numerator)
		{
			if (integer)std::cout << "(";
			std::cout << numerator << "/" << denominator;
			if (integer)std::cout << ")";
		}
		else if (integer == 0)std::cout << 0;
		std::cout << std::endl;
		return *this;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer -= integer;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
	/*result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	//result.to_proper();
	return result.to_proper();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);
	return is;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	double a = 5;
	std::cout << a << std::endl;

	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single argument constructor
	B.print();

	Fraction C(1, 2);//Constructor
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;	//CopyConstructor
	E.print();

	Fraction F;
	F = E;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK
	Fraction A(2, 1, 2);
	Fraction B(3, 4, 5);
	A.print();
	B.print();
	Fraction C = A * B;
	C.print();
	A.print();
	B.print();
	A *= B;
	A.print();

	double a = 2.5;
	double b = 3.14;
	double c = a * b;
#endif

	/*for (double i = 0.25; i < 10; i++)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/
#ifdef INPUT_OUTPUT_CHECK
	Fraction A(1, 4);
	std::cout << A++ << std::endl;
	std::cout << "Введите целую часть, числитель и знаменатель через пробел соответственно: ";
	std::cin >> A;
	std::cout << "Вы ввели: " << A << std::endl;
#endif // INPUT_OUTPUT_CHECK

#ifdef TYPE_CONVERSIONS
	int a = 2;
	double b = 3.14;
	a = b;
	std::cout << a << std::endl;
	Fraction A = (Fraction)4;	//Single argument constructor
	A = (Fraction)5;	//operator=                   
	std::cout << A << std::endl;

//http://www.cplusplus.com/doc/tutorial/typecasting/
	a = (int)A;	//C-like cast notation
	a = int(A);	//Functional notation
	std::cout << a << std::endl;
	std::cout << "\n--------------------------------\n";
	A(2, 3, 10);
	b = A;
	std::cout << b << std::endl;
#endif // TYPE_CONVERSIONS

}

/*
	Type conversions:
	Single argument constructor
*/