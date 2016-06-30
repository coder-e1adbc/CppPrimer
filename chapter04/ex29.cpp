#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int x[10];
	int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;	// 10
	cout << sizeof(p) / sizeof(*p) << endl; // 2 sizeof(pointer) / sizeof(int)

	return 0;
}
