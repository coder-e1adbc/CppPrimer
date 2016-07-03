#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int sum = 0, val = 1;
	while (val <= 10)
		sum += val, ++val;
	cout << "Sum of 1 to 10 is " << sum << endl;

	return 0;
}
