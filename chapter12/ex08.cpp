bool b()
{
	int *p = new int;
	//
	return p;			// warning: the memory which p point to will never be released.
}
