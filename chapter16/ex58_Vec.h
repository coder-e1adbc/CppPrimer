#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <iterator>

template <typename> class Vec;
template <typename T> bool operator==(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator!=(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator<(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator<=(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator>(const Vec<T> &, const Vec<T> &);
template <typename T> bool operator>=(const Vec<T> &, const Vec<T> &);

template <typename T> class Vec {
friend bool operator==<T>(const Vec<T> &, const Vec<T> &);
friend bool operator!=<T>(const Vec<T> &, const Vec<T> &);
friend bool operator< <T>(const Vec<T> &, const Vec<T> &);
friend bool operator<=<T>(const Vec<T> &, const Vec<T> &);
friend bool operator><T>(const Vec<T> &, const Vec<T> &);
friend bool operator>=<T>(const Vec<T> &, const Vec<T> &);
public:
	using value_type = T;
	Vec():
		elements(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(std::initializer_list<T>);
	Vec(const Vec &);
	Vec(Vec &&) noexcept;
	Vec& operator=(const Vec &);
	Vec& operator=(Vec &&) noexcept;
	Vec& operator=(std::initializer_list<T>);
	~Vec();
	void push_back(const T &);
	void push_back(T &&);
	template <typename... Args> void emplace_back(Args&&...);
	std::size_t size() const
		{ return first_free - elements; }
	std::size_t capacity() const
		{ return cap - elements; }
	T* begin() const
		{ return elements; }
	T* end() const
		{ return first_free; }
	void reserve(const std::size_t);
	void resize(const std::size_t, const T & = T());
	T& operator[](std::size_t n)
		{ return elements[n]; }
	const T& operator[](std::size_t n) const
		{ return elements[n]; }
private:
	static std::allocator<T> alloc;
	void chk_n_alloc();
	std::pair<T *, T *> alloc_n_copy(const T *, const T *);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};

template <typename T> inline void Vec<T>::chk_n_alloc()
	{ if (size() == capacity()) reallocate(); }

template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T> Vec<T>::Vec(std::initializer_list<T> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T> Vec<T>::Vec(const Vec &v)
{
	auto newdata = alloc_n_copy(v.begin(), v.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T> Vec<T>::Vec(Vec &&v) noexcept:
	elements(v.elements), first_free(v.first_free), cap(v.cap)
{
	v.element = v.first = v.cap = nullptr;
}

template <typename T> Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T> Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept
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

template <typename T> Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T> Vec<T>::~Vec()
	{ free(); }
template <typename T> void Vec<T>::push_back(const T &t)
{
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template <typename T> void Vec<T>::push_back(T &&t)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::make_move_iterator(t));
}

template <typaname T> template <typename... Args>
inline void Vec<T>::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T> void Vec<T>::reserve(const std::size_t n)
{
	if (n > capacity())
	{
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for (std::size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}

template <typename T> void Vec<T>::resize(const std::size_t n, const T &t)
{
	if (n < size())
		while (first_free != elements + n)
			alloc.destroy(--first_free);
	else if (n > size())
	{
		reserve(n);
		uninitialized_fill(first_free, elements + n, t);
	}
}

template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);
	auto last = std::uninitialized_copy(b, e, data);
	return {data, last};
}

template <typename T> void Vec<T>::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T> void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
			std::make_move_iterator(end()), first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}

template <typename T> bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (auto pl = lhs.begin(), pr = rhs.begin(); pl != lhs.end(); /**/ )
		if (*pl != *pr)
			return false;
	return true;
}
template <typename T> bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	if (lhs.size() != rhs.size())
		return true;
	for (auto pl = lhs.begin(), pr = rhs.begin(); pl != lhs.end(); /**/ )
		if (*pl != *pr)
			return true;
	return false;
}
template <typename T> bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl < *pr : pr != rhs.end();
}
template <typename T> bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl <= *pr : pl == lhs.end();
}
template <typename T> bool operator>(const Vec<T> &lhs, const Vec<T> &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl > *pr : pl != lhs.end();
}
template <typename T> bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs)
{
	auto sz = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	auto pl = lhs.begin(), pr = rhs.begin();
	while (sz-- && *pl == *pr)
		++pl, ++pr;
	return sz ? *pl >= *pr : pr == rhs.end();
}

#endif
