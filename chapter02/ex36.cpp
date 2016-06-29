#include <iostream>

int main(void)
{
	int a = 3, b = 4;
	decltype(a) c = a;		// int
	decltype((b)) d = a;	// int&
	++c;
	++d;

	std::cout<< a << ' ' << b << ' ' << c << ' ' << d << std::endl;	// out: 4 4 4 4

	return 0;
}
