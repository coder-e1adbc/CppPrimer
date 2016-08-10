#ifndef QUERY_H
#define QUERY_H

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <vector>

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	using QueryResult = std::tuple<std::string,
			std::shared_ptr<std::set<line_no>>,
			std::shared_ptr<std::vector<std::string>>>;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

std::ostream& print(std::ostream &, const TextQuery::QueryResult &);

#endif
