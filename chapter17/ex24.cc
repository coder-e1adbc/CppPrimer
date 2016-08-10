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

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-.]?| *)(\\d{3})([-.]?| *)(\\d{4})";
	regex r(phone);
	string s;
	string fmt = "$2.$5.$7";
	while (getline(cin, s))
		cout << regex_replace(s, r, fmt) << endl;

	return 0;
}

