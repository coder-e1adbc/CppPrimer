#include "ex05.h"

using std::size_t;

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return price * (1- discount) * cnt;
	else
		return price * cnt;
}
