namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

	int ivar = 0;

	void manip() {
		using namespace Exercise;
		double dvar = 3.1416;
		int iobj = limit + 1;
		++ivar;		// error: reference to 'ivar' is ambiguous
		++::ivar;
	}

int main()
{
	manip();
	return 0;
}
