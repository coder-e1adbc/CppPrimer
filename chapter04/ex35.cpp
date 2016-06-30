char cval;
int ival;
unsigned ui;
float fval;
double dval;

cval = 'a' + 3;				// char -> int, int -> char
fval = ui - ival * 1.0;		// int -> double, double -> float
dval = ui * fval;			// unsigned -> float, float -> double
cval = ival + fval + dval;	// int -> float, float -> double, double -> char
