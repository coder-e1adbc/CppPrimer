#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;

int main()
{
	forward_list<int> flst{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else
			prev = curr++;

	for (const auto &val : flst)
		cout << val << ' ';
	
	return 0;
}
