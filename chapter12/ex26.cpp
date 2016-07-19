#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::allocator;
using std::string;

int main()
{
	size_t n = 100;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	string s;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	for (auto i = p; i != q; ++i)
		cout << *i << ' ';
	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);

	return 0;
}
