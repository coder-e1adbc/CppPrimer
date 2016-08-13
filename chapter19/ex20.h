#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	class QueryResult;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class TextQuery::QueryResult {
friend std::ostream& print(std::ostream &, const QueryResult &);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
			std::shared_ptr<std::vector<std::string>> f)
		: sought(s), lines(p), file(f) { }
	std::set<line_no>::iterator begin() { return lines->begin(); }
	std::set<line_no>::iterator end() { return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream &, const TextQuery::QueryResult &);