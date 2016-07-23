#include <vector>

class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	std::vector<int> data;
};

#include <algorithm>
#include <iostream>

using std::sort;
using std::cout;
using std::endl;

Foo Foo::sorted() &&
{
	cout << "sorted() && called." << endl;
	sort(data.begin(), data.end());
	return *this;
}

Foo Foo::sorted() const &
{
	cout << "sorted() const & called." << endl;
	Foo ret(*this);
	return ret.sorted();	// error: infinite call
}

int main()
{
	Foo foo;
	foo.sorted();

	return 0;
}
