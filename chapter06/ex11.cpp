#include <iostream>

using std::cout;
using std::endl;

void reset(int &);

int main(void)
{
	int val(42);
	cout << val << endl;
	reset(val);
	cout << val << endl;

	return 0;
}

void reset(int &val)
{
	val = 0;
}
