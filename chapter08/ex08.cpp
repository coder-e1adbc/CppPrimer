#include "Sales_data.h"
#include <fstream>

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cerr << "usage: a.exe soursefile outfile" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	ofstream out(argv[2], ofstream::app);
	Sales_data total;
	if (read(in, total))
	{
		Sales_data trans;
		while (read(in, trans))
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(out, total) << endl;
				total = trans;
			}
		print(out, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -2;
	}

	return 0;
}
