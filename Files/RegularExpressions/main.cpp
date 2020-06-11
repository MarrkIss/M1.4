#include<iostream>
#include<string>
#include<regex>

//#define NAME_CHECK
#define GROUP_CHECK

void main()
{
#ifdef NAME_CHECK
	std::string name;
	std::cout << "Type oyur name: ";
	std::cin >> name;
	std::cout << name << std::endl;
	std::regex rgx("[A-Z][a-z]{1,50}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default) << std::endl;
#endif // NAME_CHECK

#ifdef GROUP_CHECK
	std::string group;
	std::cout << "Type group: ";
	std::cin >> group;
	std::regex rgx("(ST|PS(_SB|_VS)_(PU|PV|DU|DV)_\\d\\d)");
	std::cout << std::regex_match(group, rgx, std::regex_constants::match_default);
#endif // GROUP_CHECK

}