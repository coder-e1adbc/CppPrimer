#include <iostream>
#include ".\Sales_data.h"
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::runtime_error;

int main(void)
{
	Sales_data data1, data2;
	double price = 0.0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	try {
		if (data1.bookNo != data2.bookNo)
			throw runtime_error("Data must refer to the same ISBN");
		unsigned total_sold = data1.units_sold + data2.units_sold;
		double total_revenue = data1.revenue + data2.revenue;
		cout << data1.bookNo << ' ' << total_sold << ' ' << total_revenue << ' ';
		if(total_sold)
			cout << total_revenue / total_sold << endl;
		else
			cout << "(no sales)" << endl;
	} catch (runtime_error err) {
		cout << err.what() << endl;
	}

	return 0;
}
