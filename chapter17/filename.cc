#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <regex>
using std::regex;
using std::regex_search;
using std::smatch;

#include <string>
using std::string;

int main()
{
	regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	smatch results;
	string filename;
	while (cin >> filename)
		if (regex_search(filename, results, r))
			cout << results.str() << endl;

	return 0;
}
