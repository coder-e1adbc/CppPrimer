#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

//	string version
int main(void)
{
	string s1("Hello, world!");
	string s2("hello, world!");

	cout << ((s1 == s2) ? "Equal" : "Not equal") << endl;

	return 0;
}

/*	C style string
	
int main(void)
{
	const char ca1[] = "Hello, world!";
	const char ca2[] = "hello, world!";

	cout << ((strcmp(ca1, ca2)) ? "Not equal" : "Equal") << endl;

	return 0;
}
*/
