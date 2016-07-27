#include "ex28.h"

using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
using std::runtime_error;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) { }
void StrBlob::check(size_type i, const string &msg) const
{
	if (i > data->size())
		throw out_of_range(msg);
}
string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}
ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}
string& StrBlob::operator[](size_type n)
{
	check(n, "subscript past end of StrBlob");
	return (*data)[n];
}
const string& StrBlob::operator[](size_type n) const
{
	check(n, "subscript past end of StrBlob");
	return (*data)[n];
}


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end of StringBlobPtr");
	return (*p)[curr];
}
string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "subscript past end of StrBlobPtr");
	return (*p)[n];
}
const string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "subscript past end of StrBlobPtr");
	return (*p)[n];
}
StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}
StrBlobPtr operator+(const StrBlobPtr &s, ptrdiff_t n)
{
	string msg = n > 0 ? "addition past end of StrBlobPtr" :
						"addition past begin of StrBlobPtr";
	check(s.curr + n, msg);
	StrBlobPtr ret = s;
	ret.curr += n;
	return ret;
}
StrBlobPtr operator-(const StrBlobPtr &s, ptrdiff_t n)
{
	return s + (-n);
}
ptrdiff_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr - rhs.curr;
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound ConstStrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end of ConstStringBlobPtr");
	return (*p)[curr];
}
const string& ConstStrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "subscript past end of ConstStrBlobPtr");
	return (*p)[n];
}
ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}
ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}
ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
	ConstStrBlobPtr ret = *this;
	++*this;
	return ret;
}
ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
	ConstStrBlobPtr ret = *this;
	--*this;
	return ret;
}
ConstStrBlobPtr operator+(const ConstStrBlobPtr &s, ptrdiff_t n)
{
	string msg = n > 0 ? "addition past end of StrBlobPtr" :
						"addition past begin of StrBlobPtr";
	check(s.curr + n, msg);
	ConstStrBlobPtr ret = s;
	ret.curr += n;
	return ret;
}
ConstStrBlobPtr operator-(const ConstStrBlobPtr &s, ptrdiff_t n)
{
	return s + (-n);
}
ptrdiff_t operator-(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr - rhs.curr;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data <= *lhs.data;
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data > *rhs.data;
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data >= *rhs.data;
}
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr == rhs.wptr &&
		   lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}
bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
}
bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.wptr == rhs.wptr &&
		   lhs.curr == rhs.curr;
}
bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}
bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}
bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}
bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
}
