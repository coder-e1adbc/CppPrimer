#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main(void)
{
	constexpr int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	// ver.1
	for (const auto &p : ia)
		for (auto q : p)
			cout << q << ' ';
	cout << endl;

	// ver.2	no change
	for (size_t i = 0; i != 3; ++i)
		for (size_t j = 0; j!= 4; ++j)
			cout << ia[i][j] << ' ';
	cout << endl;

	// ver.3
	for (auto p = begin(ia); p != end(ia); ++p)
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ';
	cout << endl;

	return 0;
}
