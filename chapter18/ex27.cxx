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
	void print(std::vector<double>);
	void foo(double);
protected:
	int *ival;
	std::vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
//	all visible name:
//		Derived::sval
//		Base2::fval
//		MI::print
//		MI::foo
//		MI::ival
//		MI::dvec
//		cval
//		dval
	dval = Base1::dval + Derived::dval;
	Base2::fval = *dvec.cend();
	sval[0] = MI::cval;
}
