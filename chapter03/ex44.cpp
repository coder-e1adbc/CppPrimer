#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

using Int_array = int[4];

int main(void)
{
	constexpr int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	// ver.1
	for (const Int_array &p : ia)
		for (const int q : p)
			cout << q << ' ';
	cout << endl;

	// ver.2 	no change
	for (size_t i = 0; i != 3; ++i)
		for (size_t j = 0; j!= 4; ++j)
			cout << ia[i][j] << ' ';
	cout << endl;

	// ver.3
	for (const Int_array (*p) = begin(ia); p != end(ia); ++p)
		for (const int *q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ' ;
	cout << endl;

	return 0;
}
