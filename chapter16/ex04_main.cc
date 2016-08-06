#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "ex04.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;

int main()
{
	vector<int> vec{0, 1, 2, 3, 4, 5};
	list<string> lst{"a", "b", "c", "d", "e"};
	auto pos = find(vec.cbegin(), vec.cend(), 9) - vec.cbegin();
	if (pos == vec.size())
		cout << "Not found." << endl;
	else
		cout << "Found at " << pos << endl;

	*find(lst.begin(), lst.end(), string("c")) = string("o");
	for (const auto &s : lst)
		cout << s << " ";

	return 0;
}
