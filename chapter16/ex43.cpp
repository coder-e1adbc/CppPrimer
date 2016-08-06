template <typename T> void g(T &&val);
int i = 0;
const int ci = i;

g(i = ci);	// T: int &
