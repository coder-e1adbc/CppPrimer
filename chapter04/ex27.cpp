#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	unsigned long ul1 = 3, ul2 = 7;

	cout << (ul1 & ul2) << endl	// 3
		 << (ul1 | ul2) << endl	// 7
		 << (ul1 && ul2) << endl	// 1
		 << (ul1 || ul2) << endl;	// 1

	return 0;
}
