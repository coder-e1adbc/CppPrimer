#include <string>

using std::string;

string name(string str, string prefix, string suffix)
{
	str.insert(0, 1, ' ');
	str.insert(0, prefix);
	str.insert(str.size(), " ");
	str.insert(str.size(), suffix);

	return str;
}
