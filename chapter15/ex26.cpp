#include "ex26.h"

using std::size_t;
using std::cout;
using std::endl;

Quote& Quote::operator=(const Quote &rhs)
{
    bookNo = rhs.bookNo;
	price = rhs.price;
    cout << "operator=(const Quote &) called." << endl;
	return *this;
}
Quote& Quote::operator=(Quote &&rhs)
{
    bookNo = std::move(rhs.bookNo);
	price = rhs.price;
    cout << "operator=(Quote &&) called." << endl;
	return *this;
}

Disc_quote& Disc_quote::operator=(const Disc_quote &rhs)
{
	Quote::operator=(rhs);
	quantity = rhs.quantity;
	discount = rhs.discount;
    cout << "operator=(const Disc_quote &) called." << endl;
	return *this;
}
Disc_quote& Disc_quote::operator=(Disc_quote &&rhs)
{
	Quote::operator=(std::move(rhs));
	quantity = rhs.quantity;
	discount = rhs.discount;
    cout << "operator=(Disc_quote &&) called." << endl;
	return *this;
}
Bulk_quote& Bulk_quote::operator=(const Bulk_quote &rhs)
{
	Disc_quote::operator=(rhs);
    cout << "operator=(const Bulk_quote &) called." << endl;
}
Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs)
{
	Disc_quote::operator=(std::move(rhs));
    cout << "operator=(Bulk_quote &&) called." << endl;
}
double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return price * (1- discount) * cnt;
	else
		return price * cnt;
}
