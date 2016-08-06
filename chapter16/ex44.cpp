template <typename T> void g(T val);
int i = 0;
const int ci = i;

g(i);		// int
g(ci);		// const int
g(i * ci);	// int

template <typename T> void g(const T &val);
int i = 0;
const int ci = i;

g(i);		// int
g(ci);		// const int
g(i * ci);	// const int
