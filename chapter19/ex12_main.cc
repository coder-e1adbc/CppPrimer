#include <iostream>
using std::cout;
using std::endl;

#include "ex12.h"

int main()
{
	auto pdata = Screen::data();
	Screen s(25, 80, 'o');
	cout << s.*pdata << endl;

	return 0;
}
