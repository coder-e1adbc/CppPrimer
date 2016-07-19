#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
	const char *cp1 = "Hello, ", *cp2 = "world!";
	string s1(cp1), s2(cp2);
	auto *cp = new char[strlen(cp1) + strlen(cp2) + 1];
	strcpy(cp, cp1);
	strcat(cp, cp2);
	cout << cp << endl;
	delete [] cp;
	string s = s1 + s2;
	cout << s << endl;

	return 0;
}
