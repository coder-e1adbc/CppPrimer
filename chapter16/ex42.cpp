template <typename T> void g(T &&val);
int i = 0;
const int ci = i;

			// T:			val:
g(i);		// int &		int &
g(ci);		// const int &	const int &
g(i * ci);	// int			int &&
