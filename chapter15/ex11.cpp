#include "ex11.h"
#include <iostream>

using std::size_t;
using std::cout;
using std::endl;

void Quote::debug() const
{
	cout << "bookNo: " << bookNo << endl
		 << "price: " << price << endl;
}

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return price * (1- discount) * cnt;
	else
		return price * cnt;
}
void Bulk_quote::debug() const
{
	Quote::debug();
	cout << "min_qty: " << min_qty << endl
		 << "discount: " << discount << endl;
}
