#include <string>

struct LengthEqual {
	bool operator()(std::string &s, size_t n)
		{ return s.size() == n; }
};
