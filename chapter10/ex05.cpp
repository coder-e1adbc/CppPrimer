vector<const char *> roster1, roster2;
equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());	// it will compare ptr1 with ptr2
															// but not *ptr1 with *ptr2
