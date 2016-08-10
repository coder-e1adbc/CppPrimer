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
	string name, first_phone, other_phones;
	string fmt = "$2.$5.$7";
	while (cin >> name >> first_phone && getline(cin, other_phones))
	{
		if (other_phones.empty())
			cout << name << " " << regex_replace(first_phone, r, fmt) << endl;
		else
			cout << name << regex_replace(other_phones, r, fmt) << endl;
	}

	return 0;
}

