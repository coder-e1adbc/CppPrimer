int calc(int &, int &);
int calc(const int &, const int &);

int calc(char *, char *);
int calc(const char *, const char *);

int calc(char *, char *);
int calc(char * const, char * const);	// error: ambiguous call: top-level const will be ignored
