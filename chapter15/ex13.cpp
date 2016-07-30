class base {
public:
	string name()
		{ return basename; }
	virtual void print(ostream &os)
		{ os << basename; }
private:
	string basename;
};

class derived : public base {
public:
	void print(ostream &os) {
		print(os);			// error: infinite recursion
//		base::print(os);
		os << " " << i; }
private:
	int i;
};

