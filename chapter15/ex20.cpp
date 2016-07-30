class Base { 
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};
struct Pub_Derv : public Base {
	void memfcn(Base &b) { b = *this; }		// correct
};
struct Priv_Derv : private Base {
	void memfcn(Base &b) { b = *this; }		// correct
};
struct Prot_Derv : protected Base {
	void memfcn(Base &b) { b = *this; }		// correct
};
struct Derived_from_Public : public Pub_Derv {
	void memfcn(Base &b) { b = *this; }		// correct
};
struct Derived_from_Private : public Priv_Derv {
	void memfcn(Base &b) { b = *this; }		// error: Priv_Derv private inherit
											//		  from Base
};
struct Derived_from_Protected : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }		// correct
};

int main()
{
	Base b;
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;	// correct
	p = &d2;		// error: private inheritance
	p = &d3;		// error: protected inheritance
	p = &dd1;		// correct
	p = &dd2;		// error: Priv_derv private inherit from Base
	p = &dd3;		// error: Prot_derv protected inherit from Base

	d1.memfcn(b);	// correct
	d2.memfcn(b);	// correct
	d3.memfcn(b);	// correct
	dd1.memfcn(b);	// correct
	dd2.memfcn(b);	// error
	dd3.memfcn(b);	// correct

	return 0;
}

