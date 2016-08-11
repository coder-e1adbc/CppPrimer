struct Base {
	void bar(int) {}
protected:
	int ival;
};
struct Derived1 : virtual public Base {
	void bar(char) {}
	void foo(char) {}
protected:
	char cval;
};
struct Derived2 : virtual public Base {
	void foo(int) {}
protected:
	int ival;
	char cval;
};

class VMI : public Derived1, public Derived2 {
//	must use qualification:
//		Base::bar(int);
//		Base::ival;
//		Derived1::cval;
//		Derived2::cval;
//		Derived1::foo(char);
//		Derived2::foo(int);
//
//	can use without qualification:
//		Derived1::bar(int);
//		Derived2::ival;
};
