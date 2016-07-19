int *q = new int(42), *r = new int(100);
r = q;		// the memory of 100 was lost.
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;	// the memory of 100 will be released.
