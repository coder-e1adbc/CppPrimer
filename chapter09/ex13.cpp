#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
	list<int> lst{1, 2, 3, 4, 5};
	vector<int> ivec{6, 7, 8, 9, 0};

	vector<double> dvec1(lst.cbegin(), lst.cend());
	vector<double> dvec2(ivec.cbegin(), ivec.cend());

	for (const auto &d : dvec1)
		cout << d << ' ' ;
	cout << endl;

	for (const auto &d : dvec2)
		cout << d << ' ' ;
	cout << endl;

	return 0;
}
