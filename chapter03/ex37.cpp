#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};	// error: not ending with '\0'
	const char *cp = ca;
	while (*cp)
	{
		cout << *cp << endl;
		++cp;
	}

	return 0;
}
