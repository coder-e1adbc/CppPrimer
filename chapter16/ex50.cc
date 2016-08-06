#include <iostream>

using std::cout;
using std::endl;

template <typename T> void f(T)
	{ cout << "f(T) instantiated. " << endl; }
template <typename T> void f(const T *)
	{ cout << "f(const T *) instantiated." << endl; }
template <typename T> void g(T)
	{ cout << "g(T) instantiated." << endl; }
template <typename T> void g(T *)
	{ cout << "g(T *) instantiated." << endl; }

int main()
{
	int i = 42;
	int *p = &i;
	const int ci = 0;
	const int *p2 = &ci;

	g(42);	// call void g(int)
	g(p);	// call void g(int *)
	g(ci);	// call void g(const int)
	g(p2);	// call void g(const int *)
	f(42);	// call void f(int)
	f(p);	// call void f(int *)	!! not void f(const int *)
	f(ci);	// call void f(int)
	f(p2);	// call void f(const int *)
			// instantiate void f(const T *), not void f(T)

	return 0;
}
