#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include <stdexcept>

class out_of_stock : public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s):
		std::runtime_error(s) { }
};

class isbn_mismatch : public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s):
		std::logic_error(s) { }
	isbn_mismatch(const std::string &s, const std::string &lhs,
			const std::string &rhs):
		std::logic_error(s), left(lhs), right(rhs) { }
	const std::string left, right;
};

class Sales_data;

std::ostream& operator<<(std::ostream &, const Sales_data &);
std::istream& operator>>(std::istream &, Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);
Sales_data operator-(const Sales_data &, const Sales_data &);
bool operator==(const Sales_data &, const Sales_data &);
bool operator!=(const Sales_data &, const Sales_data &);

class Sales_data{
friend std::ostream& operator<<(std::ostream &, const Sales_data &);
friend std::istream& operator>>(std::istream &, Sales_data &);
friend Sales_data operator+(const Sales_data &, const Sales_data &);
friend Sales_data operator-(const Sales_data &, const Sales_data &);
friend bool operator==(const Sales_data &, const Sales_data &);
friend bool operator!=(const Sales_data &, const Sales_data &);

public:

	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
			   bookNo(s), units_sold(n), revenue(p * n) { }
	Sales_data(std::istream &is) { is >> *this; }

	std::string isbn() const { return bookNo; }
	Sales_data& operator=(const std::string &);
	Sales_data& operator+=(const Sales_data &);
	Sales_data& operator-=(const Sales_data &);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const { return (units_sold) ? revenue / units_sold : 0; }
};

inline compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
	{ return lhs.isbn() < rhs.isbn(); }

#endif
