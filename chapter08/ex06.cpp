#include "Sales_data.h"
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "usage: a.exe soursefile" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	Sales_data total;
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
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
	{
		cerr << "No data?!" << endl;
		return -2;
	}

	return 0;
}
