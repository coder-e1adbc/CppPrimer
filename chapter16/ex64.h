#include <cstddef>
#include <vector>
#include <string>

template <typename T> std::size_t count(const std::vector<T> &vec, const T val)
{
	std::size_t cnt = 0;
	for (const auto &v : vec)
		if (v == val)
			++cnt;
	return cnt;
}

template <>
std::size_t count(const std::vector<const char *> &vec, const char * const p)
{
	std::size_t cnt = 0;
	std::string s(p);
	for (const auto &v : vec)
		if (std::string(v) == s)
			++cnt;
	return cnt;
}
