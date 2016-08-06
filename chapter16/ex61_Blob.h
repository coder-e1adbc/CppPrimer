#ifndef BLOB_H
#define BLOB_H

#include <initializer_list>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "ex61_smart_pointer.h"

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
	Blob():
		data(make_shared<std::vector<T>>()) { }
	Blob(std::initializer_list<T> il):
		data(make_shared<std::vector<T>>(il)) { }
	template <typename It> Blob(It b, It e):
		data(make_shared<std::vector<T>>(b, e)) { }
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
	shared_ptr<std::vector<T>> data;
	void check(size_type, const std::string &) const;
};

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

#endif
