class NoDefault {
public:
	NoDefault(int i) : val(i) { }
private:
	int val;
};

class C {
public:
	C() : mem(NoDefault(0)) { }
private:
	NoDefault mem;
};
