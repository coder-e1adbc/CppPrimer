#include "ex30.h"

class StrBlobPtrPtr {
public:
	StrBlobPtr& operator->() const
		{ return p; }
private:
	StrBlobPtr *p;
};
