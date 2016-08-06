#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <utility>
#include <cstddef>

template <typename> class BlobPtr;
template <typename> class ConstBlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator>(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator<=(const Blob<T> &, const Blob<T> &);
template <typename T> bool operator>=(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
friend class BlobPtr<T>;
friend class ConstBlobPtr<T>;
friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
friend bool operator!=<T>(const Blob<T> &, const Blob<T> &);
friend bool operator< <T>(const Blob<T> &, const Blob<T> &);
friend bool operator><T>(const Blob<T> &, const Blob<T> &);
friend bool operator<=<T>(const Blob<T> &, const Blob<T> &);
friend bool operator>=<T>(const Blob<T> &, const Blob<T> &);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T>);
	template <typename It> Blob(It b, It e):
		data(std::make_shared<std::vector<T>>(b, e)) { }
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(const T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	BlobPtr<T> begin();
	BlobPtr<T> end();
	ConstBlobPtr<T> cbegin() const;
	ConstBlobPtr<T> cend() const;
	T& operator[](size_type);
	const T& operator[](size_type) const;
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type, const std::string &) const;
};

template <typename T> BlobPtr<T> operator+(const BlobPtr<T> &, std::ptrdiff_t);
template <typename T> BlobPtr<T> operator-(const BlobPtr<T> &, std::ptrdiff_t);
template <typename T> std::ptrdiff_t operator-(const BlobPtr<T> &,
		const BlobPtr<T> &);
template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator>(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T> class BlobPtr {
friend BlobPtr<T> operator+<T>(const BlobPtr<T> &, std::ptrdiff_t);
friend BlobPtr<T> operator-<T>(const BlobPtr<T> &, std::ptrdiff_t);
friend std::ptrdiff_t operator-<T>(const BlobPtr<T> &, const BlobPtr<T> &);
friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
friend bool operator!=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
friend bool operator><T>(const BlobPtr<T> &, const BlobPtr<T> &);
friend bool operator<=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
friend bool operator>=<T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
	BlobPtr(): curr(0) { }
	BlobPtr(Blob<T> &a, std::size_t sz = 0): wptr(a.data), curr(sz) { }
	T& operator[](size_t);
	const T& operator[](size_t) const;
	T& operator*() const;
	T* operator->() const
		{ return & this->operator*(); }
	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t,
			const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T> ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &,
		std::ptrdiff_t);
template <typename T> ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &,
		std::ptrdiff_t);
template <typename T> std::ptrdiff_t operator-(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);
template <typename T> bool operator==(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);
template <typename T> bool operator!=(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);
template <typename T> bool operator<(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);
template <typename T> bool operator>(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);
template <typename T> bool operator<=(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);
template <typename T> bool operator>=(const ConstBlobPtr<T> &,
		const ConstBlobPtr<T> &);

template <typename T> class ConstBlobPtr {
friend ConstBlobPtr<T> operator+<T>(const ConstBlobPtr<T> &, ptrdiff_t);
friend ConstBlobPtr<T> operator-<T>(const ConstBlobPtr<T> &, ptrdiff_t);
friend ptrdiff_t operator-<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
friend bool operator==<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
friend bool operator!=<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
friend bool operator< <T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
friend bool operator><T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
friend bool operator<=<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
friend bool operator>=<T>(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);
public:
	ConstBlobPtr(): curr(0) { }
	ConstBlobPtr(const Blob<T> &a, std::size_t sz = 0):
		wptr(a.data), curr(sz) { }
	const T& operator[](std::size_t) const;
	const T& operator*() const;
	const T* operator->() const
		{ return & this->operator*(); }
	ConstBlobPtr& operator++();
	ConstBlobPtr& operator--();
	ConstBlobPtr operator++(int);
	ConstBlobPtr operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t,
			const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T> Blob<T>::Blob():
	data(std::make_shared<std::vector<T>>()) { }
template <typename T> Blob<T>::Blob(std::initializer_list<T> il):
	data(std::make_shared<std::vector<T>>(il)) { }
template <typename T> void Blob<T>::check(size_type i,
		const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T> const T& Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T> T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T> BlobPtr<T> Blob<T>::begin()
	{ return BlobPtr<T>(*this); }
template <typename T> BlobPtr<T> Blob<T>::end()
	{ return BlobPtr<T>(*this, data->size()); }
template <typename T> ConstBlobPtr<T> Blob<T>::cbegin() const
	{ return ConstBlobPtr<T>(*this); }
template <typename T> ConstBlobPtr<T> Blob<T>::cend() const
	{ return ConstBlobPtr<T>(*this, data->size()); }
template <typename T> T& Blob<T>::operator[](size_type n)
{
	check(n, "subscript past end of Blob");
	return (*data)[n];
}

template <typename T> const T& Blob<T>::operator[](size_type n) const
{
	check(n, "subscript past end of Blob");
	return (*data)[n];
}

template <typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(
		std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

template <typename T> T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "dereference past end of BlobPtr");
	return (*p)[curr];
}

template <typename T> T& BlobPtr<T>::operator[](std::size_t n)
{
	auto p = check(n, "subscript past end of BlobPtr");
	return (*p)[n];
}

template <typename T> const T& BlobPtr<T>::operator[](std::size_t n) const
{
	auto p = check(n, "subscript past end of BlobPtr");
	return (*p)[n];
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of BlobPtr");
	return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}

template <typename T> BlobPtr<T> operator+(const BlobPtr<T> &p, ptrdiff_t n)
{
	std::string msg = n > 0 ? "addition past end of BlobPtr" :
						"addition past begin of BlobPtr";
	check(p.curr + n, msg);
	BlobPtr<T> ret = p;
	ret.curr += n;
	return ret;
}
template <typename T> BlobPtr<T> operator-(const BlobPtr<T> &p, ptrdiff_t n)
	{ return p + (-n); }
template <typename T> ptrdiff_t operator-(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return lhs.curr - rhs.curr; }

template <typename T> std::shared_ptr<std::vector<T>> ConstBlobPtr<T>::check(
		std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound ConstBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

template <typename T> const T& ConstBlobPtr<T>::operator*() const
{
	auto p = check(curr, "dereference past end of ConstStringBlobPtr");
	return (*p)[curr];
}

template <typename T> const T& ConstBlobPtr<T>::operator[](std::size_t n) const
{
	auto p = check(n, "subscript past end of ConstBlobPtr");
	return (*p)[n];
}

template <typename T> ConstBlobPtr<T>& ConstBlobPtr<T>::operator++()
{
	check(curr, "increment past end of ConstBlobPtr");
	++curr;
	return *this;
}

template <typename T> ConstBlobPtr<T>& ConstBlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of ConstBlobPtr");
	return *this;
}

template <typename T> ConstBlobPtr<T> ConstBlobPtr<T>::operator++(int)
{
	ConstBlobPtr ret = *this;
	++*this;
	return ret;
}

template <typename T> ConstBlobPtr<T> ConstBlobPtr<T>::operator--(int)
{
	ConstBlobPtr ret = *this;
	--*this;
	return ret;
}
template <typename T> ConstBlobPtr<T> operator+(const ConstBlobPtr<T> &p,
		std::ptrdiff_t n)
{
	std::string msg = n > 0 ? "addition past end of BlobPtr" :
						"addition past begin of BlobPtr";
	check(p.curr + n, msg);
	ConstBlobPtr<T> ret = p;
	ret.curr += n;
	return ret;
}

template <typename T> ConstBlobPtr<T> operator-(const ConstBlobPtr<T> &p,
		std::ptrdiff_t n)
	{ return p + (-n); }
template <typename T> std::ptrdiff_t operator-(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return lhs.curr - rhs.curr; }
template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
	{ return *lhs.data == *rhs.data; }
template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
	{ return !(lhs == rhs); }
template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
	{ return *lhs.data < *rhs.data; }
template <typename T> bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
	{ return *lhs.data <= *lhs.data; }
template <typename T> bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
	{ return *lhs.data > *rhs.data; }
template <typename T> bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
	{ return *lhs.data >= *rhs.data; }
template <typename T> bool operator==(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return lhs.wptr == rhs.wptr && lhs.curr == rhs.curr; }
template <typename T> bool operator!=(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return !(lhs == rhs); }
template <typename T> bool operator<(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return lhs.curr < rhs.curr; }
template <typename T> bool operator<=(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return lhs.curr <= rhs.curr; }
template <typename T> bool operator>(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return lhs.curr > rhs.curr; }
template <typename T> bool operator>=(const BlobPtr<T> &lhs,
		const BlobPtr<T> &rhs)
	{ return lhs.curr >= rhs.curr; }
template <typename T> bool operator==(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return lhs.wptr == rhs.wptr && lhs.curr == rhs.curr; }
template <typename T> bool operator!=(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return !(lhs == rhs); }
template <typename T> bool operator<(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return lhs.curr < rhs.curr; }
template <typename T> bool operator<=(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return lhs.curr <= rhs.curr; }
template <typename T> bool operator>(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return lhs.curr > rhs.curr; }
template <typename T> bool operator>=(const ConstBlobPtr<T> &lhs,
		const ConstBlobPtr<T> &rhs)
	{ return lhs.curr >= rhs.curr; }

#endif
