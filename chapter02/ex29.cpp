i = ic;		// illegal: const int can't assign to int
p1 = p3;	
p1 = &ic;	// illegal: p1 is not a point to const
p3 = &ic;	
p2 = p1;	// const pointer can't be changed
ic = &p3;	// const int can't be changed
