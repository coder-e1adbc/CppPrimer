#include <iostream>
#include "ex02.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	Sales_data total;
	double price(0);
	if (cin >> total.bookNo >> total.units_sold >> price)
	{
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> price)
		{
			trans.revenue = trans.units_sold * price;
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				cout << total.isbn() << '\t' << total.units_sold << '\t'
					 << total.revenue << '\t' << total.avg_price() << endl;
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		cout << total.isbn() << '\t' << total.units_sold << '\t'
			 << total.revenue << '\t' << total.avg_price() << endl;
	} else
	{
		cerr << "No data?!" << endl;
		return -1;
	}

	return 0;
}
