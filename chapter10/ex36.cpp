#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::list;
using std::find;
using std::copy;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	list<int> lst(in, eof);
	*find(lst.rbegin(), lst.rend(), 0) = 42;
	copy(lst.cbegin(), lst.cend(), out);

	return 0;
}
