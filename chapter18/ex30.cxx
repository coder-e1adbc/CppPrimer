class Base { 
public:
	Base(int i = 0): ival(i) { }
	Base(const Base &b): ival(b.ival) { }
private:
	int ival;
};

class D1 : virtual public Base {
public:
	D1(int b = 0, int d = 0): Base(b), ival(d) { }
	D1(const D1 &d): Base(d), ival(d.ival) { }
private:
	int ival;
};

class D2 : virtual public Base {
public:
	D2(int b = 0, int d = 0): Base(b), ival(d) { }
	D2(const D2 &d): Base(d), ival(d.ival) { }
private:
	int ival;
};

class MI : public D1, public D2 {
public:
	MI(int b = 0): Base(b), D1(), D2(), ival(0) { }
	MI(int b, int d1, int d2, int m = 0):
		Base(b), D1(b, d1), D2(b, d2), ival(m) { }
	MI(const MI &m): Base(m), D1(m), D2(m), ival(m.ival) { }
private:
	int ival;
};

class Final : public MI {
public:
	Final(int b = 0): Base(b), MI() { }
	Final(int b, int d1, int d2, int m = 0):
		Base(b), MI(b, d1, d2, m), ival(0) { }
	Final(int b, int d1, int d2, int m, int f):
		Base(b), MI(b, d1, d2, m), ival(f) { }
	Final(const Final &f):
		Base(f), MI(f), ival(f.ival) { }
private:
	int ival;
};
