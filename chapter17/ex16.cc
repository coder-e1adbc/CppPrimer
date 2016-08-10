#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::regex_search;
using std::smatch;

int main()
{
	string pattern("[^c]ei");
	regex r(pattern);
	smatch results;
	string test_str = "receipt freind theif receive";
	if (regex_search(test_str, results, r))
		cout << results.str() << endl;

	return 0;
}
