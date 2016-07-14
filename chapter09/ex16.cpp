#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
	list<int> lst{1, 2, 3, 4, 5, 6};
	vector<int> vec{1, 2, 3, 4, 5};

	cout << (lst == list<int>(vec.cbegin(), vec.cend()) ? "eq" : "not eq") << endl;

	return 0;
}
