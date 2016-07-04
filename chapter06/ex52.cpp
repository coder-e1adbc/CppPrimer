void manip(int, int);
double dobj;

manip('a', 'z');		// level 3: promotion: char -> int
manip(55.4, dobj);		// level 4: arithmetic conversion: double -> int
