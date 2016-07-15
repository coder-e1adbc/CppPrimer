#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a, b;
	auto f = [](int a, int b) { return a + b; };
	cin >> a >> b;
	cout << f(a, b) << endl;

	return 0;
}
