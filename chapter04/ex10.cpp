#include <iostream>

using std::cin;

int main(void)
{
	int val;
	while ((cin >> val) && val != 42)
		;

	return 0;
}
