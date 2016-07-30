#include "ex15.h"

using std::size_t;

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return price * (1- discount) * cnt;
	else
		return price * cnt;
}
