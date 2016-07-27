// if-then-else
struct ITE {
	int operator()(bool b, int val1, int val2)
		{ return b ? val1 : val2; }
};
