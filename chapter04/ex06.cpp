#include <iostream>

int main(void)
{
	int val;
	std::cin >> val;
	std::cout << ((val % 2) ? "odd" : "even") << std::endl;

	return 0;
}
