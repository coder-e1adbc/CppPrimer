class A { };
class B : public A { };
class C : public B { };
class X { };
class Y { };
class Z : public X, public Y { };
class MI : public C, public Z { };

//	A() -> B() -> C() --------------------
//	                   X() ------        |-->MI()
//	                            |--> Z() -
//	                        Y() -
MI mi;
