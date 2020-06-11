//STL - Standard Template Library
/*
Containers:
1. Associative containers: (key-value)
   -map;
   -milti_map;
   -set;
   -multiset;
-----------------------------
2. Sequence containers:
   -array - статический массив;
   -vector - описывает динамический массив;
   -forward_list - односвязный список;
   -list - двусзяный список;
*/

#include<iostream>
#include<vector>

#define STL_VECTOR

//template<typename T>
void print(const std::vector<double>& vec)
{
	for (std::vector<double>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		//++*it;
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
}

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_VECTOR
	//Vector - это контейнер, который хранит 
	//элементы в виде диначеского массива.
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	vec.push_back(55);
	/*try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//std::cout << vec[i] << "\t";
			std::cout << vec.at(i) << "\t";
		}
		std::cout << std::endl;
		std::cout << "Size:\t\t" << vec.size() << std::endl;
		std::cout << "Capacity:\t" << vec.capacity() << std::endl;
		std::cout << "MaxSize:\t" << vec.max_size() << std::endl;
		vec.resize(5);
		//vec.shrink_to_fit();
		vec.reserve(30);
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl;
		std::cerr << e.what() << std::endl;
	}*/

	for (int i : vec)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	std::cout << "Size:\t\t" << vec.size() << std::endl;
	std::cout << "Capacity:\t" << vec.capacity() << std::endl;
	std::cout << "MaxSize:\t" << vec.max_size() << std::endl;

	int index;
	int value;
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> value;
	/*std::vector<int>::iterator position = vec.begin()+index;
	vec.insert(position, value);*/
	vec.insert(vec.begin() + index, value);

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

#endif // STL_VECTOR

}