int ival = 1.01;
int &rval1 = 1.01;	// illegal: the initial value must be object
int &rval2 = ival;
int &rval3;			// illegal: reference must be initialized
