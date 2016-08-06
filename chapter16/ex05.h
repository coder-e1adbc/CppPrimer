#include <iostream>

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
	for (size_t i = 0; i != N; ++i)
		std::cout << arr[i] << std::endl;
}
