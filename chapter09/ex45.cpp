#include <string>

using std::string;

string name(string str, string prefix, string suffix)
{
	str.insert(str.begin(), 1, ' ');
	str.insert(str.begin(), prefix.begin(), prefix.end());
	str.append(1, ' ');
	str.append(suffix);

	return str;
}
