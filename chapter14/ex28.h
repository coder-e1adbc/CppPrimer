#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
friend bool operator==(const StrBlob &, const StrBlob &);
friend bool operator!=(const StrBlob &, const StrBlob &);
friend bool operator<(const StrBlob &, const StrBlob &);
friend bool operator>(const StrBlob &, const StrBlob &);
friend bool operator<=(const StrBlob &, const StrBlob &);
friend bool operator>=(const StrBlob &, const StrBlob &);
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string>);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &s) { data->push_back(s); }
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;
	std::string& operator[](size_type);
	const std::string& operator[](size_type) const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type, const std::string &) const;
};

class StrBlobPtr {
friend StrBlobPtr operator+(const StrBlobPtr &, ptrdiff_t);
friend StrBlobPtr operator-(const StrBlobPtr &, ptrdiff_t);
friend ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
public:
	StrBlobPtr(): curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
	std::string& deref() const;
	std::string& operator[](size_t);
	const std::string& operator[](size_t) const;
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

class ConstStrBlobPtr {
friend ConstStrBlobPtr operator+(const ConstStrBlobPtr &, ptrdiff_t);
friend ConstStrBlobPtr operator-(const ConstStrBlobPtr &, ptrdiff_t);
friend ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
public:
	ConstStrBlobPtr(): curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
	std::string& deref() const;
	const std::string& operator[](size_t) const;
	ConstStrBlobPtr& operator++();
	ConstStrBlobPtr& operator--();
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr operator--(int);
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);
StrBlobPtr operator+(const StrBlobPtr &, ptrdiff_t);
StrBlobPtr operator-(const StrBlobPtr &, ptrdiff_t);
ptrdiff_t operator-(const StrBlobPtr &, const StrBlobPtr &);
bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);
ConstStrBlobPtr operator+(const ConstStrBlobPtr &, ptrdiff_t);
ConstStrBlobPtr operator-(const ConstStrBlobPtr &, ptrdiff_t);
ptrdiff_t operator-(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

#endif
