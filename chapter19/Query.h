//	changed for Ex.19.2.2
#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <memory>

class Query_base {
friend class Query;
protected:
	virtual ~Query_base() = default;
};

class WordQuery : public Query_base {
friend class Query;
private:
	WordQuery(const std::string &s):
		query_word(s) { }
	std::string query_word;
};

class Query {
public:
	Query(const std::string &s):
		q(new WordQuery(s)) { }
private:
	std::shared_ptr<Query_base> q;
};

class NotQuery : public Query_base {
public:
	NotQuery(const Query &q):
		query(q) { }
	Query query;
};

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const std::string &l, const std::string &r, std::string s):
		lhs(Query(l)), rhs(Query(r)), opSym(s) { }
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
public:
	AndQuery(const std::string &left, const std::string &right):
		BinaryQuery(left, right, "&") { }
};

class OrQuery : public BinaryQuery {
public:
	OrQuery(const std::string &left, const std::string &right):
		BinaryQuery(left, right, "|") { }
};

#endif
