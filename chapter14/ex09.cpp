#include "ex09.h"

using std::istream;
using std::ostream;


Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);

	return sum;
}

ostream& operator<<(ostream &os, const Sales_data &item)
{
	os << item.bookNo << ' ' << item.units_sold << ' '
		<< item.revenue << ' ' << item.avg_price();
	return os;
}

istream& operator>>(istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}
