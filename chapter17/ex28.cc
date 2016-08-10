#include <iostream>
using std::cout;
using std::endl;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <cstddef>
using std::size_t;

unsigned random_unsigned()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 9);
	return u(e);
}

int main()
{
	for (size_t i = 0; i != 10; ++i)
		cout << random_unsigned() << endl;

	return 0;
}
