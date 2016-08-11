#include <iostream>
using std::cin;
using std::cerr;
using std::endl;

#include "ex09.h"

int main()
{
	Sales_data item1, item2, sum;
	while (cin >> item1 >> item2)
		sum = item1 + item2;

	return 0;
}
