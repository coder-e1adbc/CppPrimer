#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto &g = ci;

	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << g << ' ' << endl;

	a = 42;		
	b = 42;
	c = 42;
//	d = 42;		// illegal: d is an int pointer
//	e = 42;		// illegal: e is a low-level int pointer
//	g = 42;		// illegal: g is a const reference

	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << g << ' ' << endl;

	return 0;
}
