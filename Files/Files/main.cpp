#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
#define EXCHANGE
#define INPUT_STRINGS

void main()
{
#ifdef WRITE_TO_FILE
	cout << "Hello";
	ofstream fout;
	fout.open("D:\\File.txt"/*,std::ios_base::app*/);
	fout << "Hello";
	fout.close();
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin("_main.cpp");
	const int n = 256;
	char buffer[n] = {};

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: File not found" << endl;
	}

	fin.close();
#endif

#ifdef EXCHANGE
	//1) Create buffers to read from streams:
	const int n = 50;
	char sz_mac_buffer[n];	//sz - String Zero
	char sz_ip_buffer[n];

	char sz_source_filename[n] = "201 RAW.txt";
	char sz_result_filename[n]{};
	cout << "Input file name: ";
	std::cin.getline(sz_result_filename, n);

	//2) Open streams:
	ifstream fin(sz_source_filename);
	ofstream fout(sz_result_filename);


	//3) Read/Write files:
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		}
	}
	else
	{
		cout << "File not found" << endl;
	}

	fout.close();
	fin.close();

	char command[n] = "notepad ";
	strcat(command, sz_result_filename);
	system(command);
#endif

	/*int a, b, c;
	cout << "Input 3 numbers: ";
	cin >> a >> b >> c;
	cout << a << "\t" << b << "\t" << c << endl;*/

	/*const int n = 50;
	char str[n]{};
	cout << "Input line: ";
	cin >> str;
	cout << str;*/
}