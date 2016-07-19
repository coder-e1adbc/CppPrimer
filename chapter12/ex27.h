#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery {
public:
	using size_type = std::std::vector<std::string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(std::string &) const;

private:
	std::shared_ptr<vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<size_type>>> word_map;
};

class QueryResult {
friend std::ostream& print(std::ostream &, QueryResult);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<size_type>> p, std::shared_ptr<std::vector<std::string>> f)
		: sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<size_type>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream & print(ostream &, QueryResult);
