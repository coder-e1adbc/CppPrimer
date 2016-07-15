#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using std::sort;
using std::find_if_not;

int main()
{
	istream_iterator<Sales_item> in(cin), eof;
	ostream_iterator<Sales_item> out(cout, "\n");
	vector<Sales_item> vec(in, eof);
	sort(vec.begin(), vec.end(), [](const Sales_item &i1, const Sales_item &i2) { return i1.isbn() < i2.isbn(); });
	auto start = vec.cbegin(), stop(start);
	while (start != vec.cend())
	{
		stop = find_if_not(start, vec.cend(), [start](const Sales_item &item) { return start->isbn() == item.isbn(); });
		out = accumulate(start + 1, stop, *start);
		start = stop;
	}

	return 0;
}
