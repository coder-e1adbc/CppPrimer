#include "ex04.h"
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
using std::initializer_list;
using std::string;
using std::tuple;
using std::make_tuple;
using std::get;
using std::vector;

#include <algorithm>
using std::equal_range;
using std::accumulate;

#include <fstream>
using std::ifstream;

vector<vector<Sales_data>> createFiles(initializer_list<string> file)
{
	Sales_data book;
	vector<vector<Sales_data>> ret;
	for (const auto &f : file)
	{
		ifstream in(f);
		vector<Sales_data> sales;
		while (in >> book)
			sales.push_back(book);
		sort(sales.begin(), sales.end(), compareIsbn);
		ret.push_back(sales);
	}
	return ret;
}

vector<matches> findBook(const vector<vector<Sales_data>> &files,
		const string &book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(),
						found.first, found.second));
	}
	return ret;
}

void reportResults(istream &is, ostream &os,
		const vector<vector<Sales_data>> &files)
{
	string s;
	while (is >> s)
	{
		auto trans = findBook(files, s);
		if (trans.empty())
		{
			cout << s << " not found in any stores." << endl;
			continue;
		}
		for (const auto &store : trans)
			os << "store " << get<0>(store) << " sales: "
			   << accumulate(get<1>(store), get<2>(store), Sales_data(s))
			   << endl;
	}
}
