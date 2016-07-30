#include "ex03.h"
#include <iostream>

using std::ostream;
using std::endl;
using std::size_t;

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os	<< "ISBN: " << item.isbn() << " # sold: " << n
		<< " total due: " << ret << endl;
	return ret;
}
