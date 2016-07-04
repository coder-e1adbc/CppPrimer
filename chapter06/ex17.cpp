#include <cctype>
#include <string>

using std::string;

bool have_capital(const string &s)
{
	auto index = s.size();
	while (index--)
		if (isupper(s[index]))
			return true;
	return false;
}

void tolower(string &s)
{
	auto index = s.size();
	while (index--)
		s[index] = tolower(s[index]);
}
