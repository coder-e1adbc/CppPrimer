template <typename T> f1(T, T);
template <typename T1, typename T2> f2(T1, T2);
int i = 0, j = 42;
int *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;

f1(p1, p2);		// calls f1(int *, int *)
f2(p1, p2);		// calls f2(int *, int *)
f1(cp1, cp2);	// calls f1(const int *, const int *)
f2(cp1, cp2);	// calls f2(const int *, const int *)
f1(p1, cp1);	// calls f1(const int *, const int *)
f2(p1, cp1);	// calls f2(int *, const int *)
