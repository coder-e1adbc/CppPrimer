#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact(int val)
{
	int ret(1);
	while (val > 1)
		ret *= val--;

	return ret;
}

int main(void)
{
	cout << "enter an integer: ";
	int val;
	cin >> val;
	cout << val << "! = " << fact(val) << endl;

	return 0;
}
