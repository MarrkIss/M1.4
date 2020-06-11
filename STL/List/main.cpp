#include<iostream>
#include<forward_list>
#include<list>
#include<vector>

//#define FORWARD_LIST
//#define LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef FORWARD_LIST
	//forward_list - это контейнер, который хранит данные в виде односвязного списка.
	std::forward_list<int> fl = { 3, 5, 8, 13, 21 };
	fl.push_front(34);
	fl.push_front(55);
	for (std::forward_list<int>::iterator it = fl.begin(); it != fl.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	/*for (int i = 0; i < 5; i++)
	{
		std::cout << fl[i] << "\t";
	}*/

	int index;
	int value;
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> value;
	try
	{
		std::forward_list<int>::iterator position = fl.begin();
		for (int i = 0; i < index - 1; i++)
		{
			position++;
			if (position == fl.end())throw std::exception("Error: Out of range");
		}
		fl.insert_after(position, value);
		
		for (int i : fl)
		{
			std::cout << i << "\t";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif

#ifdef LIST
	std::list<int> list = { 3, 5, 8, 13,21 };
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::wcout << *it << "\t";
	}
	std::wcout << std::endl;

	std::wcout << "Size: " << list.size() << std::endl;
#endif

	std::vector<int> vec = { 3, 5, 8, 13, 21 };
	try
	{
		for (int i = 0; i < 10; i++)
		{
			//std::cout << vec[i] << "\t";
			std::cout << vec.at(i) << "\t";
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/*
Anybody here me??????

Nooo



*/