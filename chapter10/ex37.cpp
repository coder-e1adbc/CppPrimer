#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::ostream_iterator;
using std::vector;
using std::list;
using std::copy;

int main()
{
	ostream_iterator<int> out(cout, " ");
	vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> lst;
	auto it =back_inserter(lst);
	copy(vec.crbegin() + 2, vec.crbegin() + 7, it);
	copy(lst.cbegin(), lst.cend(), out);

	return 0;
}
