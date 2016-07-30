base bobj, *bp1 = &bobj, &br1 = bobj;
derived dobj;
base *bp2 = &dobj, &br2 = dobj;

bobj.print();	// base::print()
dobj.print();	// derived::print()
bp1->name();	// base::name()
bp2->name();	// base::name()
br1.print();	// derived::print()
br2.print();	// derived::print()
