#include "ex47.h"
#include <iostream>

using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_copy_n;
using std::pair;
using std::cout;
using std::endl;

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
	cout << "String(const String &) called." << endl;
}

String& String::operator=(const String &s)
{
	auto newdata = alloc_n_copy(s.bg, s.ed);
	free();
	bg = newdata.first;
	ed = newdata.second;
	cout << "String& operator=(const String &) called." << endl;
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
	
