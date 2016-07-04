#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(int &);
void print(const int *beg, const int *end);
void print(int [], size_t n);

int main(void)
{
	int i = 0;
	int j[2] = {0, 1};

	print(i);
	print(begin(j), end(j));
	print(j, end(j) - begin(j));

	return 0;
}

void print(int &val)
{
	cout << val << endl;
}

void print(const int *beg, const int *end)
{
	while (beg != end)
		cout << *beg++ << ' ' ;
	cout << endl;
}

void print(int a[], size_t n)
{
	for (size_t i = 0; i != n; ++i)
	   cout << a[i] << ' ' ;	
	cout << endl;
}
