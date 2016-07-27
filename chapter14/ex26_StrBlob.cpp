#include "ex26_StrBlob.h"

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
	auto p = check(curr, "dereference past end of StrBlobPtr");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	auto p = check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "subscript past end of StringBlobPtr");
	return (*p)[n];
}
const string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "subscript past end of StringBlobPtr");
	return (*p)[n];
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
	auto p = check(curr, "dereference past end of ConstStrBlobPtr");
	return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	auto p = check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}
const string& ConstStrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "subscript past end of ConstStringBlobPtr");
	return (*p)[n];
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
