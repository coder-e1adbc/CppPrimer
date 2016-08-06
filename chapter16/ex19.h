#include <iostream>

// valid only for string, vector, deque and array
template <typename T> void print(T &t)
{
	for (typename T::size_type i = 0; i != t.size(); ++i)
		std::cout << t[i] << std::endl;
}
