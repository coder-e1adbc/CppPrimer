namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

	int ivar = 0;

	void manip() {
		using Exercise::ivar;
		using Exercise::dvar;
		using Exercise::limit;
		double dvar = 3.1416;	// error: redeclaration of 'double dvar'
		int iobj = limit + 1;
		++ivar;		// Exercise::ivar
		++::ivar;
	}

int main()
{
	manip();
	return 0;
}
