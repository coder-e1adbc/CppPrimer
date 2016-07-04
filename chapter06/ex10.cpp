#include <iostream>

using std::cout;
using std::endl;

void swap(int *, int *);

int main(void)
{
	int val1 = 0, val2 = 42;
	cout << val1 << '\t' << val2 << endl;
	swap(&val1, &val2);
	cout << val1 << '\t' << val2 << endl;

	return 0;
}

void swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

