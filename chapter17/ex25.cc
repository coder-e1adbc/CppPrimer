#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::regex_replace;
using namespace std::regex_constants;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-.]?| *)(\\d{3})([-.]?| *)(\\d{4})";
	regex r(phone);
	string name, phones;
	string fmt = "$2.$5.$7";
	while (cin >> name && getline(cin, phones))
	{
		cout << name << " "
			 << regex_replace(phones, r, fmt,
					 format_no_copy | format_first_only)
			 << endl;
	}

	return 0;
}

