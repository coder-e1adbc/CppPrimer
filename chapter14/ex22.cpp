#include "ex22.h"

using std::string;
using std::istream;
using std::ostream;

Sales_data& Sales_data::operator=(const string &s)
{
	bookNo = s;
	revenue = units_sold = 0;
	return *this;
}
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
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

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data diff = lhs;
	diff -= rhs;
	return diff;
}
 
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo == rhs.bookNo &&
		   lhs.units_sold == rhs.units_sold	&&
		   lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
