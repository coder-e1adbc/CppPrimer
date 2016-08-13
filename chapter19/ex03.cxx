class A { };
class B : public A { };
class C : public B { };
class D : public B, public A { };

A *pa = new C;
B *pb = dynamic_cast<B *>(pa);

B *pb = new B;
C *pc = dynamic_cast<C *>(pb);	// error: pb points to a B but not a D

A *pa = new D;					// error: ambiguous: D -> B -> A
								//                   D -> A
B *pb = dynamic_cast<B *>(pa);
