#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::copy;
using std::vector;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> vec(in, eof);
	sort(vec.begin(), vec.end());
	copy(vec.cbegin(), vec.cend(), out);

	return 0;
}
