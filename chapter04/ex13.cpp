#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	{
		int i;
		double d;
		d = i = 3.5;
		cout << i << ' ' << d << endl;		// 3 3
	}
	{
		int i;
		double d;
		i = d = 3.5;
		cout << i << ' ' << d << endl;		// 3 3.5
	}

	return 0;
}
