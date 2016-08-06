#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::max;

int main()
{
	int i(42);
	double d(3.14);

//	cout << max(i ,d) << endl;	// illegal.
	cout << max<double>(i ,d) << endl;

	return 0;
}
