pv = (void*) ps;	// pv = static_cast<void*>(const_cast<string*>(ps));
i = int(*pc);		// i = static_cast<int>(*pc);
pv = &d;			// pv = static_cast<void*>(&d);
pc = (char*) pv;	// pc = static_cast<char*>(pv);