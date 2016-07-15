#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int val = 10;
	auto f = [&val]() { return !((val > 0) ? val-- : 0); };
	for (auto i = 0; i < 12; ++i)
		cout << f() << ' ' << val << endl;

	return 0;
}
