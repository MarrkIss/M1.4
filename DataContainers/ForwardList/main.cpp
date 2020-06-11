#include<iostream>

class ForwardList
{
	class Element
	{
		int Data;
		Element* pNext;
		static int count;
	public:
		const int getData()const
		{
			return this->Data;
		}
		const Element* getNext()const
		{
			return this->pNext;
		}
		Element(int Data, Element* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			count++;
#ifdef DEBUG
			std::cout << "EConstructor:\t" << this << std::endl;
#endif // DEBUG

		}
		~Element()
		{
			count--;
#ifdef DEBUG
			std::cout << "EDestructor:\t" << this << std::endl;
#endif // DEBUG

		}
		friend class ForwardList;
	};

	Element* Head;
	int size;
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp)
		{
			this->Temp = Temp;
#ifdef DEBUG_IT
			std::cout << "ItConstructor:\t" << this << std::endl;
#endif // DEBUG_IT

		}
		/*Iterator(const Iterator& other)
		{
			this->Temp = other.Temp;
			std::cout << "ItConstructor:\t" << this << std::endl;
		}*/
		~Iterator()
		{
#ifdef DEBUG_IT
			std::cout << "ItDestructor:\t" << this << std::endl;
#endif // DEBUG_IT

		}

		const int& operator*() const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}

		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			if(Temp)Temp = Temp->pNext;
			return old;
		}

		bool operator==(const Iterator& other) const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other) const
		{
			return this->Temp != other.Temp;
		}
	};
	/*const Element* getHead()const
	{
		return this->Head;
	}*/

	const Iterator begin()const
	{
		//Возвращает итератор на начало контейнера
		return Head;
	}
	const Iterator end()const
	{
		//Возвращает итератор на конец контейнера
		return nullptr;
	}

	int get_size()const
	{
		return size;
	}
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	explicit ForwardList(int size) :ForwardList()
	{
		while (size--)push_front(0);
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	ForwardList(std::initializer_list<int> il) :ForwardList()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		for (int const *it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
		std::cout << "ILconstructor:\t" << this << std::endl;
	}
	ForwardList(const ForwardList& that) :ForwardList()
	{
		/*Element* Temp = that.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}*/
		for (Element* Temp = that.Head; Temp != nullptr; Temp = Temp->pNext)push_back(Temp->Data);
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	ForwardList(ForwardList&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		std::cout << "MoveConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//				Operators:

	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		std::cout << "MoveAssignment:\t" << this << std::endl;
		return *this;
	}

	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}

	//				Methods:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		Temp->pNext = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index > size)
		{
			std::cout << "Error: Out of range" << std::endl;
			return;
		}
		//1) Создаем элемент:
		Element* New = new Element(Data);
		//2) Доходим до нужной позиции в списке:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) Вставляем новый элемент в список:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;
		size--;
	}

	void pop_back()
	{
		//Удаление элемента с конца списка.
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index >= size)
		{
			std::cout << "Error: Out of range" << std::endl;;
			return;
		}
		/*if (index == size - 1)
		{
			pop_back();
			return;
		}*/
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* buffer = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete buffer;
		size--;
	}

	//			methods:
	void print()
	{
		std::cout << "\n-------------------------------------\n";
		std::cout << "Head:\t" << Head << std::endl;
		//Element* Temp = Head;	//Temp - это итератор.
		//						//Итератор - это указатель, при помощи которого 
		//						//можно получить доступ к элементам структуры данных.
		//while (Temp != nullptr)
		//{
		//	std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
		//	Temp = Temp->pNext;	//Переход на следующий элемент.
		//}

		/*for (Element* Temp = Head; Temp; Temp=Temp->pNext)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
		}*/
		for (Iterator it = Head; 
			it != nullptr; 
			++it)
		{
			std::cout << *it << "\t";
		}
		std::cout << std::endl;

		std::cout << "List size:\t" << size << std::endl;
		std::cout << "\n-------------------------------------\n";
	}

	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};

int ForwardList::Element::count = 0;

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (const ForwardList::Element* Temp = right.Head; Temp; Temp = Temp->getNext())
	{
		cat.push_back(Temp->getData());
	}
	std::cout << "Global operator +" << std::endl;
	return cat;
}

void print(int arr[])
{
	std::cout << sizeof(arr) << std::endl;
	std::cout << typeid(arr).name() << std::endl;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;

	/*for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/
}

//#define BASE_CHECK
//#define OPERATORS_AND_CONSTRUCTORS_CHECK
//#define RANGE_BASED_FOR
//#define PREFORMANCE_ARR
#define PREFORMANCE_LIST

void main()
{
	setlocale(LC_ALL, "");

	int n;
	//std::cout << "Input list size: "; std::cin >> n;
#ifdef BASE_CHECK
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 100);
	}
	//fl.push_back(123);
	fl.print();

	int index;
	int data;

	/*std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> data;
	fl.insert(index, data);
	fl.print();*/

	/*fl.pop_front();
	fl.pop_back();
	fl.print();*/

	/*std::cout << "Input index: "; std::cin >> index;
	fl.erase(index);
	fl.print();*/
#endif // BASE_CHECK

	/*int a = 2;
	double b = 3;
	ForwardList list1(5);
	for (int i = 0; i < n; i++)
	{
		list1[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << list1[i] << "\t";
	}
	std::cout << std::endl;*/

#ifdef OPERATORS_AND_CONSTRUCTORS_CHECK
	ForwardList list1 = { 3, 5, 8, 13, 21 };
	list1.print();

	ForwardList list2 = { 34, 55, 89 };
	list2.print();

	std::cout << "\n---------------------------------------------\n";
	ForwardList list3;
	list3 = list1 + list2;
	std::cout << "\n---------------------------------------------\n";
	for (int i = 0; i < list3.get_size(); i++)std::cout << list3[i] << "\t";
	std::cout << std::endl;

	/*ForwardList list2;
	list2 = list1;
	list2.print();*/
#endif // OPERATORS_AND_CONSTRUCTORS_CHECK

	/*int arr[] = { 3, 5, 8, 13, 21 };
	std::cout << sizeof(arr) << std::endl;
	std::cout << typeid(arr).name() << std::endl;
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;

	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	print(arr);*/

#ifdef RANGE_BASED_FOR
	ForwardList list = { 3, 5, 8, 13, 21 };
	//list.print();
	for (int i : list)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif

#ifdef PREFORMANCE_ARR
	//int n;
	std::cout << "Input size: "; std::cin >> n;
	int* arr = new int[n] {};
	std::cout << "Memory allocated." << std::endl;
	std::cout << "Loading data....." << std::endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	std::cout << "Data loaded." << std::endl;
	std::cout << "-----------------" << std::endl;
	for (int i = 0; i < n; i++)
	{
		//std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << "Data usage......" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Releasing memory...." << std::endl;
	delete[] arr;
	std::cout << "Memory released." << std::endl;
#endif

#ifdef PREFORMANCE_LIST
	//int n;
	std::cout << "Input size: "; std::cin >> n;
	ForwardList list(n);
	std::cout << "Memory allocated." << std::endl;
	std::cout << "Loading data....." << std::endl;
	for (int i = 0; i < n; i++)
	{
		list[i] = rand();
	}
	std::cout << "Data loaded." << std::endl;
	std::cout << "-----------------" << std::endl;
	for (int i = 0; i < n; i++)
	{
		//std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << "Data usage......" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Releasing memory...." << std::endl;
	list.~ForwardList();
	std::cout << "Memory released." << std::endl;
#endif
}