#include <vector>

class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	std::vector<int> data;
};

#include <algorithm>

using std::sort;

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return *ret;
}
