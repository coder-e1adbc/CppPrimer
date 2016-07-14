#include <iostream>
#include <list>
#include <forward_list>

using std::cout;
using std::endl;
using std::list;
using std::forward_list;

int main()
{
	list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = li.begin();
	while (iter != li.end())
		if (*iter % 2)
		{
			iter = li.insert(iter, *iter);
			++++iter;
		}else
			iter = li.erase(iter);

	for (const auto &val : li)
		cout << val << ' ' ;
	cout << endl;

	forward_list<int> fli = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto prev = fli.before_begin();
	auto curr = fli.begin();
	while (curr != fli.end())
		if (*curr % 2)
		{
			fli.insert_after(prev, *curr);
			prev = curr++;
		}else
			curr = fli.erase_after(prev);

	for (const auto &val : fli)
		cout << val << ' ' ;

	return 0;
}
