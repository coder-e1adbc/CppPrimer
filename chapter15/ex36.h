#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include <iostream>

class Query_base {
public:
	Query_base()
		{ std::cout << "Query_base() called." << std::endl; }
friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual std::string rep() const = 0;
};

class Query;

class WordQuery : public Query_base {
friend class Query;
private:
	WordQuery(const std::string &s):
		query_word(s)
		{ std::cout << "WordQuery(const string &) called." << std::endl; }
	std::string rep() const override {
		std::cout << "WordQuery::rep() called." << std::endl;
		return query_word;
	}
	std::string query_word;
};

class Query {
friend Query operator~(const Query &);
friend Query operator&(const Query &, const Query &);
friend Query operator|(const Query &, const Query &);
public:
	Query(const std::string &s):
		q(new WordQuery(s))
		{ std::cout << "Query(const string &) called." << std::endl; }
	std::string rep() const {
		std::cout << "Query::rep() called." << std::endl;
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query):
		q(query)
		{ std::cout << "Query(shared_ptr<Query_base>) called." << std::endl; }
	std::shared_ptr<Query_base> q;
};
inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}

class NotQuery : public Query_base {
friend Query operator~(const Query &);
private:
	NotQuery(const Query &q):
		query(q)
		{ std::cout << "NotQuery(const Query &) called." << std::endl; }
	std::string rep() const override {
		std::cout << "NotQuery::rep() called." << std::endl;
		return "~(" + query.rep() + ")";
	}
	Query query;
};
inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s):
		lhs(l), rhs(r), opSym(s)
		{ std::cout << "BinaryQuery(const Query &, const Query &, string) called."
					<< std::endl; }
	std::string rep() const override {
		std::cout << "BinaryQuery::rep() called." << std::endl;
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
friend Query operator&(const Query &, const Query &);
private:
	AndQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "&")
		{ std::cout << "AndQuery(const Query &, const Query &) called."
					<< std::endl; }
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
friend Query operator|(const Query &, const Query &);
private:
	OrQuery(const Query &left, const Query &right):
		BinaryQuery(left, right, "|")
		{ std::cout << "OrQuery(const Query &, cosnt Query &) called."
					<< std::endl; }
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif
