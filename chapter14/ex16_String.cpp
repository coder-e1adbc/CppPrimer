#include "ex16_String.h"

using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_copy_n;
using std::pair;
using std::ostream;

allocator<char> String::alloc;

String::String(const char *p)
{
	bg = alloc.allocate(sizeof(p));
	ed = uninitialized_copy_n(p, sizeof(p), bg);
}

String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.bg, s.ed);
	bg = newdata.first;
	ed = newdata.second;
}

String::String(String &&s) noexcept:
	bg(s.bg), ed(s.ed)
{
	s.bg = s.ed = nullptr;
}

String& String::operator=(const String &rhs)
{
	auto newdata = alloc_n_copy(rhs.bg, rhs.ed);
	free();
	bg = newdata.first;
	ed = newdata.second;
	return *this;
}

String& String::operator=(String &&rhs)
{
	if (this != &rhs)
	{
		free();
		bg = rhs.bg;
		ed = rhs.ed;
		rhs.bg = rhs.ed = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
}

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void String::free()
{
	if (bg)
	{
		for (auto p = ed; p != bg; )
			alloc.destroy(--p);
		alloc.deallocate(bg, ed - bg);
	}
}

ostream& operator<<(ostream &os, String &s)
{
	for (char c : s)
		os << c;
	return os;
}

bool operator==(const String &lhs, const String &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (auto pl = lhs.begin(), pr = rhs.begin(); pl != lhs.end(); )
		if (*pl++ != *pr++)
			return false;
	return true;
}

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
