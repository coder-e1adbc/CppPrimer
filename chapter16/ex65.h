#include <string>
#include <sstream>

template <typename T> std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> std::string debug_rep(const T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

std::string debug_rep(const std::string &s)
{
	return '"' + s + '"';
}

template<>
std::string debug_rep(char * const p)
{
	return debug_rep(std::string(p));
}

template<>
std::string debug_rep(const char * const p)
{
	return debug_rep(std::string(p));
}

