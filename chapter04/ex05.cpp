#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	cout << -30 * 3 + 21 / 5 << endl	// -86
		 << -30 + 3 * 21 / 5 << endl	// -18
		 <<  30 / 3 * 21 % 5 << endl	//  0
		 << -30 / 3 * 21 % 4 << endl;	// -2

	return 0;
}
