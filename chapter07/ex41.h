#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data;

Sales_data add(const Sales_data, const Sales_data);
std::istream& read(std::istream &, Sales_data &);
std::ostream& print(std::ostream &, const Sales_data &);

class Sales_data{

friend Sales_data add(const Sales_data, const Sales_data);
friend std::istream& read(std::istream &, Sales_data &);
friend std::ostream& print(std::ostream &, const Sales_data &);

public:

	Sales_data(const std::string &s, unsigned n, double p) :
			   bookNo(s), units_sold(n), revenue(p * n)
	  {	std::cout << "Sales_data(string, unsigned, double) called." << std::endl; }
	Sales_data() : Sales_data("", 0, 0)
	  {	std::cout << "Sales_data() called." << std::endl; }
	Sales_data(const std::string &s) : Sales_data(s, 0, 0)
	  {	std::cout << "Sales_data(string) called." << std::endl; }
	Sales_data(std::istream &is) : Sales_data()
	{
		read(is, *this);
		std::cout << "Sales_data(istream&) called." << std::endl;
	}

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	std::string bookNo;
unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const { return (units_sold) ? revenue / units_sold : 0; }
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
