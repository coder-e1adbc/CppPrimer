#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "ex21.h"

int main()
{
	Token t1, t2;
	t1.show();
	t1 = 'a';
	t2 = string("abc");
	t1.show();
	t2.show();
	t1 = 42;
	t1.show();
	t1 = t2;
	t1.show();
	t1 = 3.14;
	t1.show();

	return 0;
}
