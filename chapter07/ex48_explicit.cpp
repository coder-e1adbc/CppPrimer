#include "ex48.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	string null_isbn("9-999-99999-9");
	Sales_data item1(null_isbn);
	Sales_data item2("9-999-99999-9");

	print(cout, item1) << endl;
	print(cout, item2) << endl;

	return 0;
}
