#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::sregex_iterator;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string test_str = "receipt freind theif receive";
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
			it != end_it; ++it)
		cout << it->str() << endl;

	return 0;
}
