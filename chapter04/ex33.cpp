#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int x = 0, y = 0;
	true ? ++x, ++y : --x, --y;		// (true ? ++x, ++y : --x), --y;
	cout << x << ' ' << y << endl;

	return 0;
}
