#include "ex41.h"

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	Sales_data data1;
	cout << endl;
	Sales_data data2("978-7-121-15535-2");
	cout << endl;
	Sales_data data3("978-7-121-15535-2", 1, 128);
	cout << endl;
	Sales_data data4(cin);
	
	return 0;
}
