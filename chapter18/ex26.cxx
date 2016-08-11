#include <string>
#include <vector>

struct Base1 {
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};
struct Base2 {
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};
struct Derived : public Base1 {
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	using Derived::print;	// +
	using Base2::print;		// +
	void print(std::vector<double>);
protected:
	int *ival;
	std::vector<double> dvec;
};

MI mi;
mi.print(42);
