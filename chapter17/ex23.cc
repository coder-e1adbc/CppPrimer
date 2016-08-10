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
	return m[2].matched || !m[1].matched;
}

int main()
{
	regex r("\\d{5}(-)?(\\d{4})?");
	string s;
	smatch m;
	while (cin >> s)
		cout << (regex_match(s, m, r) && valid(m) ? "match" : "not match")
			 << endl;
	
	return 0;
}
