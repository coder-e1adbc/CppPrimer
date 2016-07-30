#include "ex30.h"

using std::ostream;
using std::endl;
using std::shared_ptr;
using std::multiset;
using std::size_t;

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return price * (1- discount) * cnt;
	else
		return price * cnt;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os  << "ISBN: " << item.isbn() << " # sold: " << n
        << " total due: " << ret << endl;
    return ret;
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend();
              iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
	return sum;
}
