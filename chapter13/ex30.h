#include <utility>
#include <string>
#include <iostream>

class HasPtr {
public:
	friend void swap(HasPtr &, HasPtr &);
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &orig): ps(new std::string(*(orig.ps))), i(orig.i) { }
	HasPtr& operator=(const HasPtr &);
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "swap() called." << std::endl;
}
