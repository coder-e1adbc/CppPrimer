#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <cstddef>
#include <functional>
#include <memory>

class Delete {
public:
	template <typename T> void operator()(T *p) const 
		{ delete p; };
};

template <typename T, typename D> class unique_ptr;

template <typename T> class shared_ptr {
public:
	shared_ptr():
		pointer(nullptr), del(nullptr), use(new std::size_t(0)) { }
	explicit shared_ptr(T *p, std::function<void(T*)> d = Delete()):
		pointer(p), del(d), use(new std::size_t)
		{ *use = p ? 1 : 0; }
	template <typename D> explicit shared_ptr(unique_ptr<T, D> &&u):
		pointer(u.pointer), del(u.del), use(new std::size_t)
		{ *use = pointer ? 1 : 0; u.pointer = nullptr; }
	shared_ptr(const shared_ptr &s):
		pointer(s.pointer), del(s.del), use(s.use)
		{ if (pointer) ++*s.use; }
	shared_ptr(shared_ptr &&s) noexcept:
		pointer(s.pointer), del(std::move(s.del)), use(s.use)
		{ s.pointer = nullptr; }
	shared_ptr& operator=(const shared_ptr &);
	shared_ptr& operator=(shared_ptr &&) noexcept;
	~shared_ptr();
	explicit operator bool() const { return pointer == nullptr; }
	T operator*() { return *pointer; }
	T* operator->() { return & *pointer; }
	T* get() { return pointer; }
	const T operator*() const { return *pointer; }
	const T* operator->() const { return & *pointer; }
	const T* get() const { return pointer; }
	bool unique() const { return *use == 1; }
	std::size_t use_count() const { return *use; }
	void reset(T* = nullptr, std::function<void(T*)> = Delete());
	void swap(shared_ptr &) noexcept;
private:
	T* pointer;
	std::function<void (T*)> del;
	std::size_t *use;
};

template <typename T, typename D = Delete> class unique_ptr {
friend shared_ptr<T>::shared_ptr(unique_ptr<T, D> &&);
public:
	explicit unique_ptr(D d = Delete()):
		pointer(nullptr), del(d) { }
	explicit unique_ptr(T *p, D d = Delete()):
		pointer(p), del(d) { }
	unique_ptr(const unique_ptr &) = delete;
	unique_ptr(unique_ptr &&u):
		pointer(u.pointer), del(u.del)
		{ u.pointer = nullptr; }
	unique_ptr& operator=(const unique_ptr &) = delete;
	unique_ptr& operator=(unique_ptr &&);
	~unique_ptr()
		{ del(pointer); }
	unique_ptr& operator=(std::nullptr_t /* nullptr */ );
	explicit operator bool() const { return pointer == nullptr; }
    T operator*() { return *pointer; }
    T* operator->() { return & *pointer; }
    T* get() { return pointer; }
    const T operator*() const { return *pointer; }
	const T* operator->() const { return & *pointer; }
    const T* get() const { return pointer; }
	void swap(unique_ptr &) noexcept;
	T* release();
	void reset(T *);
private:
	T* pointer;
	D del;
};

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr &rhs)
{
	if (rhs.pointer)
		++*rhs.use;
	if (pointer && !--*use)
		del(pointer);
	pointer = rhs.pointer;
	del = rhs.del;
	use = rhs.use;
	return *this;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr &&rhs) noexcept
{
	if (this != &rhs)
	{
		if (pointer && !--*use)
			del(pointer);
		pointer = rhs.pointer;
		del = std::move(rhs.del);
		use = rhs.use;
		rhs.pointer = nullptr;
	}
	return *this;
}

template <typename T> shared_ptr<T>::~shared_ptr()
{
	if (pointer && !--*use)
		del(pointer);
	delete use;
}

template <typename T> void shared_ptr<T>::reset(T* p, std::function<void(T*)> d)
{
	if (pointer != p)
	{
		if (pointer && !--*use)
			del(pointer);
		pointer = p;
		*use = pointer ? 1 : 0;
	}
	del = d;
}

template <typename T> inline void shared_ptr<T>::swap(shared_ptr &rhs) noexcept
{
	using std::swap;
	swap(pointer, rhs.pointer);
	swap(del, rhs.del);
	swap(use, rhs.use);
}

template <typename T, typename D> unique_ptr<T, D>& unique_ptr<T, D>::operator=(unique_ptr &&rhs)
{
	if (this != &rhs)
	{
		pointer = rhs.pointer;
		del = rhs.del;
		rhs.pointer = nullptr;
	}
	return *this;
}

template <typename T, typename D>
unique_ptr<T, D>& unique_ptr<T, D>::operator=(std::nullptr_t /* nullptr */ )
{
	del(pointer);
	pointer = nullptr;
	return *this;
}

template <typename T, typename D>
void unique_ptr<T, D>::swap(unique_ptr &rhs) noexcept
{
    using std::swap;
    swap(pointer, rhs.pointer);
    swap(del, rhs.del);
}

template <typename T, typename D> T* unique_ptr<T, D>::release()
{
	auto p(pointer);
	del(pointer);
	pointer = nullptr;
	return p;
}

template <typename T, typename D> void unique_ptr<T, D>::reset(T *p)
{
	if (pointer != p)
	{
		del(pointer);
		pointer = p;
	}
}

template <typename T>
inline void swap(shared_ptr<T> &lhs, shared_ptr<T> &rhs) noexcept
	{ lhs.swap(rhs); }
template <typename T, typename D>
inline void swap(unique_ptr<T, D> &lhs, unique_ptr<T, D> &rhs) noexcept
	{ lhs.swap(rhs); }
#endif
