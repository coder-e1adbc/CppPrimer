#include <iostream>
using std::cout;
using std::endl;

#include "ex02.h"

int main()
{
	StrVec svec;
	svec.push_back("hello, ");
	svec.push_back("world.");
	for (const auto s : svec)
		cout << s << endl;

	return 0;
}
