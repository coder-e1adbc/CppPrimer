#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::smatch;
using std::sregex_iterator;

bool valid(const smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (!m[4].matched || m[4].str()[0] == ' ');
	else
		return !m[3].matched && m[4].str()[0] == m[6].str()[0];
}

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-.]?| *)(\\d{3})([-.]?| *)(\\d{4})";
	regex r(phone);
	string s;
	while (getline(cin, s))
		for (sregex_iterator it(s.begin(), s.end(), r), end_it;
				it != end_it; ++it)
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;

	return 0;
}
