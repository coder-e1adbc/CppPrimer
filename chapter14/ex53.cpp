class SmallInt {
friend SmallInt operator+(const SmallInt &, const SmallInt &);
public:
	SmallInt(int = 0);
	operator int() const
		{ return val; }
private:
	std::size_t val;
};

SmallInt s1;

double d = s1 + 3.14;	// ambiguous error
// SmallInt operator+(const SmallInt &, const SmallInt &):	3.14 -> int => SmallInt
// double operator+(const double, const double):	s1 => int -> double

double d = static_cast<double>(s1) + 3.14;
