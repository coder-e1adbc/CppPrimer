template <typename T> T clac(T, int);
template <typename T> T fcn(T, T);
double d;
float f;
char c;

calc(c, 'c');	// legal. calls clac(char, int)
calc(d, f);		// legal. calls calc(double, int)
fcn(c, 'c');	// legal. calls fcn(char, char)
fcn(d, f);		// illegal. can't instantiate fcn(double, float)
