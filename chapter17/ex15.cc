#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::regex_search;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	string test_str;
	while (cin >> test_str)
		cout << (regex_search(test_str, r) ? "false" : "ture") << endl;

	return 0;
}
