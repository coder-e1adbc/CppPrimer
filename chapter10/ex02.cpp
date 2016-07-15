#include <iostream>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::count;

int main()
{
	int val;
	list<int> lst;
	while (cin >> val)
		lst.push_back(val);
	
	cout << count(lst.cbegin(), lst.cend(), val) << endl;

	return 0;
}
