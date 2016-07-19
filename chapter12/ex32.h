#include "ex22.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery {
public:
	using line_no = StrBlob::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
friend std::ostream& print(std::ostream &, const QueryResult &);
public:
	using line_no = StrBlob::size_type;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f)
		: sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	StrBlob file;
};

std::ostream& print(std::ostream &, const QueryResult &);
