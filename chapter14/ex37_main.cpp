#include <iostream>
#include <string>
#include <algorithm>
#include "ex37.h"

using std::cout;
using std::endl;
using std::string;
using std::replace_if;

int main()
{
	Equal eq;
	string s("Hello, world!");
	cout << s << endl;
	replace_if(s.begin(), s.end(), [&eq](char c) { return eq(c, 'o'); }, '0');
	cout << s << endl;

	return 0;
}
