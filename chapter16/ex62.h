#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data;

std::ostream& operator<<(std::ostream &, const Sales_data &);
std::istream& operator>>(std::istream &, Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);
Sales_data operator-(const Sales_data &, const Sales_data &);
bool operator==(const Sales_data &, const Sales_data &);
bool operator!=(const Sales_data &, const Sales_data &);
//	template <typename> struct std::hash;

class Sales_data{
friend std::ostream& operator<<(std::ostream &, const Sales_data &);
friend std::istream& operator>>(std::istream &, Sales_data &);
friend Sales_data operator+(const Sales_data &, const Sales_data &);
friend Sales_data operator-(const Sales_data &, const Sales_data &);
friend bool operator==(const Sales_data &, const Sales_data &);
friend bool operator!=(const Sales_data &, const Sales_data &);
friend struct std::hash<Sales_data>;

public:

	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
			   bookNo(s), units_sold(n), revenue(p * n) { }
	Sales_data(std::istream &is) { is >> *this; }

	std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data &);
	Sales_data& operator-=(const Sales_data &);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const { return (units_sold) ? revenue / units_sold : 0; }
};

namespace std {
template <> struct hash<Sales_data>
{
	typedef size_t result_type;
	typedef Sales_data argument_type;
	size_t operator()(const Sales_data &) const;
};
inline size_t hash<Sales_data>::operator()(const Sales_data &s) const
{
	return hash<std::string>()(s.bookNo) ^
		   hash<unsigned>()(s.units_sold) ^
		   hash<double>()(s.revenue);
}
}

#endif
