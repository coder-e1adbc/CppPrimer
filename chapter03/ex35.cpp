#include <iterator>

int main(void)
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto pbeg = std::begin(array);
	auto pend = std::end(array);
	while (pbeg != pend)
		*pbeg++ = 0;

	return 0;
}
