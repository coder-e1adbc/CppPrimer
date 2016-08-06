#include <iostream>
#include "ex02.h"
#include "Sales_data.h"

using std::cout;
using std::endl;

int main()
{
	Sales_data data1("123"), data2("234");
//	error: no match for 'operator<'
	cout << compare(data1, data2) << endl;

	return 0;
}
