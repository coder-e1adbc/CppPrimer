#include <iostream>
using std::cout;
using std::endl;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <cstddef>
using std::size_t;

#include <climits>

unsigned random_unsigned(unsigned seed,
		unsigned min = 0, unsigned max = UINT_MAX)
{
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}

int main()
{
	for (size_t i = 0; i != 10; ++i)
		cout << random_unsigned(32767, 0, 255) << endl;

	return 0;
}
