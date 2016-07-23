#ifndef HASPTR_H
#define HASPTR_H

#include <utility>
#include <string>

class HasPtr {
public:
	friend void swap(HasPtr &, HasPtr &);
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr &orig):
		ps(new std::string(*orig.ps)), i(orig.i) { }
	HasPtr(HasPtr &&);
	HasPtr& operator=(const HasPtr &);
	HasPtr& operator=(HasPtr &&);
	bool operator<(const HasPtr &rhs) const { return *ps < *rhs.ps; }
	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};

#endif
