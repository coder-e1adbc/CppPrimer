#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using std::copy;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> vec(in, eof);
	auto it = vec.cend();	
	do
		*out++ = *--it;
	while (it != vec.cbegin());

	return 0;
}
