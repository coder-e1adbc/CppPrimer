class A { };
class B : public A { };
class C : public B { };
class X { };
class D : public X, public C { };

D *pd = new D;

// all allowed
X *px = pd;
A *pa = pd;
B *pb = pd;
C *pc = pd;


