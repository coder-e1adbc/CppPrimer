#include <iostream>

template <typename T> void print(T &t)
{
	for (const auto &v : t)
		std::cout << v << std::endl;
}
