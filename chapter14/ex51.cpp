void calc(int);
void calc(LongDouble);
double dval;
calc(dval);		// dval: double -> int => calc(int);
				// dval: double => LongDouble => calc(LongDouble);	*best*
