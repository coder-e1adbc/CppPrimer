struct LongDouble {
	LongDouble(double = 0.0);
	operator double();
	operator float();
	LongDouble operator+(const SmallInt &);
};
LongDouble operator+(LongDouble &, double);

SmallInt si;
LongDouble ld;

ld = si + ld;
// LongDouble operator+(LongDouble &, double):	si => int -> double => LongDouble
//												ld => double

ld = ld + si;
// LongDouble LongDouble::operator+(const SmallInt &):	exact match
// LongDouble operator+(LongDouble &, double):	si => int -> double
