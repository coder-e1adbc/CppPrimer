#include "ex18_StrVec.h"
#include <iterator>

using std::string;
using std::allocator;
using std::uninitialized_copy;
using std::pair;
using std::initializer_list;
using std::make_move_iterator;

allocator<string> StrVec::alloc;

StrVec::StrVec(const initializer_list<string> &lst)
{
	auto newdata = alloc_n_copy(lst.begin(), lst.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept:
	elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.element = s.first = s.cap = nullptr;
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)
{
	chk_n_alloc();
	alloc.construct(first_free++, make_move_iterator(s));
}

void StrVec::reserve(const size_t n)
{
	if (n > capacity())
	{
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}

void StrVec::resize(const size_t n, const string &s)
{
	if (n < size())
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	else if (n > size())
	{
		reserve(n);
		uninitialized_fill(first_free, elements + n, s);
	}
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);
	auto last = uninitialized_copy(b, e, data);
	return {data, last};
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (auto pl = lhs.begin(), pr = rhs.begin(); pl != lhs.end(); )
		if (*pl != *pr)
			return false;
	return true;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl < *pr : pr != rhs.end();
}
bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl <= *pr : pl == lhs.end();
}
bool operator>(const StrVec &lhs, const StrVec &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl > *pr : pl != lhs.end();
}
bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl >= *pr : pr == rhs.end();
}
