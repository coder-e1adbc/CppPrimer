#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	vector<int> vec;
	list<int> lst;

	for (const auto &val : ia)
	{
		vec.push_back(val);
		lst.push_back(val);
	}

	auto lit = lst.begin();
	while (lit != lst.end())
		if (*lit % 2)
			lit = lst.erase(lit);
		else
			++lit;

	auto vit = vec.begin();
	while(vit != vec.end())
		if (*vit % 2 == 0)
			vit = vec.erase(vit);
		else
			++vit;

	for (const auto &val : lst)
		cout << val << ' ' ;
	cout << endl;
	for (const auto &val : vec)
		cout << val << ' ' ;
	cout << endl;

	return 0;
}
