#include <iostream>
#include "ex47.h"

using std::cout;
using std::endl;

void f(int v1, int &v2)
{
	cout << v1 << " " << ++v2 << endl;
}

void g(int && i , int & j)
{
	cout << i << " " << j << endl;
}

int main()
{
	int i = 42;
	int &ri = i;
	flip(f, i, 12);
	flip(g, ri, 12);
}
