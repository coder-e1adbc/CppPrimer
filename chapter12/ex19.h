#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
friend class StrBlobPtr;
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
