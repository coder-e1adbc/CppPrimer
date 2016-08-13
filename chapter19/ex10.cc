#include <iostream>
using std::cout;
using std::endl;

#include <typeinfo>

class A { virtual f() { }; };
class B : public A { };
class C : public B { };

int main()
{
	A *pa = new C;
	cout << typeid(pa).name() << endl;	// pointer to A

	C cobj;
	A &ra = cobj;
	cout << typeid(&ra).name() << endl;	// pointer to A

	B *px = new B;
	A &ra2 = *px;
	cout << typeid(ra2).name() << endl;	// B

	delete pa;
	delete px;

	return 0;
}
