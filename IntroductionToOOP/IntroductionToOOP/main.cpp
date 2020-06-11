#include<iostream>
using namespace std;

//Operators overloading

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		if (x >= -1000 && x <= 1000)	//Фильтрация значений по оси 'x'
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)	//у этого конструктора каждый параметр имеет значение по умолчанию, которое он приймет, если при вызове функции не передать соответсвеющие аргументы.
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	double operator+(const Point& other)
	{
		double sum = this->x + other.y;
		return sum;
	}

	//			Methods:
	void print()
	{
		cout << x << "\t" << y << endl;
	}

	double distance(const Point& other) const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}

	double add(const Point& other) const
	{
		return this->x + other.y;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	//B.set_x(666);
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define HOME_WORK
//#define CONSTRUCTORS_CHECK
#define COPY_ASSIGNMENT

void main()
{
	setlocale(LC_ALL, "");
	//int a;	//Объявление переменной 'a' типа 'int'
	//Point A;//Объявление переменной 'A' типа 'Point' 
	//		//или объявление объекта 'A' структуры 'Point'
	//cout << sizeof(A) << endl;
	//cout << sizeof(Point) << endl;

	////Обращение к поляи объекта:
	//A.x = 2;
	//A.y = 3;
	//cout << A.x << "\t" << A.y << endl;

	//Point* pA = &A;
	//cout << pA->x << "\t" << pA->y << endl;
	//cout << pA << endl;
	//cout << &(*pA).x << endl;
	//cout << &(*pA).y << endl;

#ifdef HOME_WORK
	Point A(2, 3);
	/*cout << A.get_x() << "\t" << A.get_y() << endl;
	A.set_x(2);
	A.set_y(3);*/
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B(4, 5);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	B.print();

	//cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
#endif // HOME_WORK

	/*cout << "\n================ Operators: ===================\n";
	int a = 2;
	int b = 3;
	cout << a + b << endl;
	cout << A.add(B) << endl;
	cout << A + B << endl;
	cout << "\n===============================================\n";*/

	/*A.operator+(B);
	или

	operator+(A, B);
	A + B;*/

	/*Point C = 5;
	C.print();

	Point D = C;
	D.print();*/

#ifdef CONSTRUCTORS_CHECK	
	Point A;	//Default constructor
	Point B(2, 3);
	Point C = B;//Copy constroctor
	Point E;	//Default constructor
	E = C;		//Copy assignment
#endif //CONSTRUCTORS_CHECK

#ifdef COPY_ASSIGNMENT
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);
#endif

}



/*
	Special members:
	1. Constrctor - это метод, который создает объект;
	2. Destructor ~;
	3. Operator=;

	Class(const Class& other);
	
*/

/*
	Правила перегрузки операторов:
	1. Перегрузить можно только существующие операторы.
		+ перегружается;
		++ перегружается;
		* перегружается;
		** НЕ перегружается;
	2. Не все существующие операторы можно перегрузить.
		Не перегружаются:
		?: - тернарный оператор;
		:: - оператор разрешения видимости; std::cout...
		. - point operator;
		.*
		#
		##



		---------------------
*/