#include<iostream>

//#define DIVISION_BY_ZERO
#define ARITHMETICAL_OVERFLOW

int factorial(int n)
{
	if (n > 12)throw std::exception("Error: Arithmetical overlow");
	unsigned int f = 1;
	for (int i = 1; i <= n; i++)
	{
		//std::cout << i << "! = ";
		f *= i;
		//std::cout << f << std::endl;
	}
	//std::cout << n << "! = " << f << std::endl;
	return f;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef DIVISION_BY_ZERO
	int a, b;
	std::cout << "Input two numbers: "; std::cin >> a >> b;
	try
	{
		std::cout << " = " << a / b << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Something happend" << std::endl;
	}
#endif // DIVISION_BY_ZERO

#ifdef ARITHMETICAL_OVERFLOW
	int n;
	std::cout << "Input number: "; std::cin >> n;
	try
	{
		std::cout << n << "! = " << factorial(n) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif
}