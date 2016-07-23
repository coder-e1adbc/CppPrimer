#ifndef TEXTQUERY
#define TEXTQUERY

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "ex40.h"

class QueryResult;

class TextQuery {
public:
	using line_no = size_t;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<StrVec> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
friend std::ostream& print(std::ostream &, const QueryResult &);
public:
	using line_no = size_t;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<StrVec> f)
		: sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<StrVec> file;
};

std::ostream& print(std::ostream &, const QueryResult &);

#endif
