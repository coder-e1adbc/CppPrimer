#include <iostream>
#include <list>
#include <deque>

using std::cout;
using std::endl;
using std::list;
using std::deque;

int main()
{
	list<int> lst{1, 2, 3, 4, 5, 6 ,7, 8 ,9, 0};
	deque<int> odd;
	deque<int> even;

	auto beg = lst.begin();
	auto end = lst.end();

	while (beg != end)
	{
		odd.push_back(*beg++);
		if (beg == end)
			break;
		even.push_back(*beg++);
	}

	for (const auto &val : odd)
		cout << val << ' ' ;
	cout << endl;

	for (const auto &val : even)
		cout << val << ' ' ;
	cout << endl;

	return 0;
}
