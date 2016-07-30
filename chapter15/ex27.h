#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <cstddef>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) { }
	std::string isbn() const
		{ return bookNo; }
	virtual double net_price(std::size_t n) const
		{ return n * price; }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price;
};

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc) { }
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;
	double net_price(std::size_t) const override;
};

#endif
