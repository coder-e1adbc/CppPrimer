#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <cstddef>
#include <iostream>
#include <memory>
#include <set>
#include <utility>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) { }
	virtual ~Quote() = default;
	std::string isbn() const
		{ return bookNo; }
	virtual double net_price(std::size_t n) const
		{ return n * price; }
	virtual Quote* clone() const &
		{ return new Quote(*this); }
	virtual Quote* clone() &&
		{ return new Quote(std::move(*this)); }
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
	Bulk_quote* clone() const & override
		{ return new Bulk_quote(*this); }
	Bulk_quote* clone() && override
		{ return new Bulk_quote(std::move(*this)); }
};

class Basket {
public:
	void add_item(const Quote &sale)
		{ items.insert(std::shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote &&sale)
		{ items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
						const std::shared_ptr<Quote> &rhs)
		{ return lhs->isbn() < rhs->isbn(); }
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};
#endif
