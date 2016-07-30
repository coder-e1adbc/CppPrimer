#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <cstddef>
#include <iostream>
#include <utility>

class Quote {
public:
	Quote():
		bookNo(std::string()), price(0)
		{ std::cout << "Quote() called." << std::endl; }
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price)
		{ std::cout << "Quote(const string &, double) called." << std::endl; }
	Quote(const Quote &q):
		bookNo(q.bookNo), price(q.price)
		{ std::cout << "Quote(const Quote &) called." << std::endl; }
	Quote(Quote &&q):
		bookNo(q.bookNo), price(q.price)
		{ std::cout << "Quote(Quote &&) called." << std::endl; }
	Quote& operator=(const Quote &);
	Quote& operator=(Quote &&);
	virtual ~Quote()
		{ std::cout << "~Quote() called." << std::endl; }
	std::string isbn() const
		{ return bookNo; }
	virtual double net_price(std::size_t n) const
		{ return n * price; }
private:
	std::string bookNo;
protected:
	double price;
};

class Disc_quote : public Quote {
public:
	Disc_quote():
		Quote()
		{ std::cout << "Disc_quote() called." << std::endl; }
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
		Quote(book, price), quantity(qty), discount(disc)
		{ std::cout << "Disc_quote(const string &, double, size_t, double) called." << std::endl; }
	Disc_quote(const Disc_quote &dq):
		Quote(dq), quantity(dq.quantity), discount(dq.discount)
		{ std::cout << "Disc_quote(const Disc_quote &) called." << std::endl; }
	Disc_quote(Disc_quote &&dq):
		Quote(std::move(dq)), quantity(dq.quantity), discount(dq.discount)
		{ std::cout << "Disc_quote(Disc_quote &&) called." << std::endl; }
	Disc_quote& operator=(const Disc_quote &);
	Disc_quote& operator=(Disc_quote &&);
	~Disc_quote()
		{ std::cout << "~Disc_quote() called." << std::endl; }
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote():
		Disc_quote()
		{ std::cout << "Bulk_quote() called." << std::endl; }
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
		Disc_quote(book, price, qty, disc)
		{ std::cout << "Bulk_quote(const string &, double, size_t, double) called." << std::endl; }
	Bulk_quote(const Bulk_quote &bq):
		Disc_quote(bq)
		{ std::cout << "Bulk_quote(const Bulk_quote &) called." << std::endl; }
	Bulk_quote(Bulk_quote &&bq):
		Disc_quote(std::move(bq))
		{ std::cout << "Bulk_quote(Bulk_quote &&) called." <<std::endl; }
	Bulk_quote& operator=(const Bulk_quote &);
	Bulk_quote& operator=(Bulk_quote &&);
	~Bulk_quote()
		{ std::cout << "~Bulk_quote() called." << std::endl; }
	double net_price(std::size_t) const override;
};

#endif
