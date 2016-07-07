#include "ex12.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	Sales_data total(cin);
	if (cin)
	{
		Sales_data trans;
		while (read(cin, trans))
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		print(cout, total) << endl;
	}
	else
		cerr << "No data?!" << endl;
	
	return 0;
}
