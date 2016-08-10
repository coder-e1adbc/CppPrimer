#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <regex>
using std::regex;
using std::regex_match;
using std::smatch;

#include <string>
using std::string;

bool valid(const smatch &m)
{
	return m[3].matched || !m[2].matched;
}

int main()
{
	regex r("(\\d{5})(-)?(\\d{4})?");
	string s;
	smatch m;
	string fmt = "$1-$3";
	while (cin >> s)
		if (regex_match(s, m, r) && valid(m))
			if (m.length(0) == 5)
				cout << m.str() << endl;
			else
				cout << m.format(fmt) << endl;
		else
			cout << "not match" << endl;
	
	return 0;
}
