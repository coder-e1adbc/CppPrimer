#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main(void)
{
	int val1, val2;
	cin >> val1 >> val2;
	if (val2 == 0)
		throw runtime_error("divided by zero");
	cout << val1 / val2 << endl;
	
	return 0;
}
