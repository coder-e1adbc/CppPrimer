auto sp = make_shared<int>();
auto p = sp.get();
delete p;	// legal, release sp.
