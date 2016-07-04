#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	cout << "enter an integer: " ;
	int val;
	cin >> val;
	cout << val << "! = " << fact(val) << endl;

	return 0;
}
