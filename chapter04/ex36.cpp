#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int i(42);
	double d(3.14);

	cout << (i *= d) << endl;

	i = 42;

	cout << (i *= static_cast<int>(d)) << endl;

	return 0;
}
