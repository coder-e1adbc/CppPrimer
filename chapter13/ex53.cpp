#include "ex53.h"

using std::string;

HasPtr::HasPtr(HasPtr &&h):
	ps(h.ps), i(h.i)
{
	h.ps = nullptr;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs)
{
	if (this != &rhs)
	{
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
