#include <cstddef>
#include <vector>

template <typename T> std::size_t count(const std::vector<T> &vec, const T val)
{
	std::size_t cnt = 0;
	for (const auto &v : vec)
		if (v == val)
			++cnt;
	return cnt;
}
