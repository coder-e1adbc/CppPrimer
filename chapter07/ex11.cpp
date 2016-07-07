#include "ex11.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Sales_data data1;
	Sales_data data2("978-7-121-15535-2");
	Sales_data data3("978-7-121-15535-2", 2, 128);
	Sales_data data4(cin);

	print(cout, data1) << endl;
	print(cout, data2) << endl;
	print(cout, data3) << endl;
	print(cout, data4) << endl;

	return 0;
}
