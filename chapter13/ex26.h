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
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string>);
	StrBlob(const StrBlob &orig):
		data(std::make_shared<std::vector<std::string>>(new std::vector<std::string>(*orig.data))) { }
	StrBlob& operator=(const StrBlob &);

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
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type, const std::string &) const;
};

class StrBlobPtr {
public:
	StrBlobPtr(): curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr(): curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
	std::string& deref() const;
	ConstStrBlobPtr& incr();
private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>> check(size_t, const std::string &) const;
};
