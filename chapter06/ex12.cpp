#include <iostream>

using std::cout;
using std::endl;

void swap(int &, int &);

int main(void)
{
	int val1 = 0, val2 = 42;
	cout << val1 << '\t' << val2 << endl;
	swap(val1, val2);
	cout << val1 << '\t' << val2 << endl;

	return 0;
}

void swap(int &val1, int &val2)
{
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}

