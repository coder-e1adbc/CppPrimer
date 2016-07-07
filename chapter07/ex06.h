#ifndef EX06_H
#define EX06_H
#include <iostream>
#include <string>

struct Sales_data{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const { return revenue / units_sold; }
};

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

std::istream& read(std::istream &is, Sales_data &item)
{
	double price(0);
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;

	return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << '\t' << item.units_sold << '\t'
	   << item.revenue << '\t' << item.avg_price();

	return os;
}
#endif
