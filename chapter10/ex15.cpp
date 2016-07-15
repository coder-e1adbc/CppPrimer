#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a, b;
	cin >> a >> b;
	auto f = [a](int b) { return a + b; };
	cout << f(b) << endl;

	return 0;
}
