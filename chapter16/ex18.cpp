//	template <typename T, typename U, typename V> void f1(T, U, V);
	template <typename T, U, typename V> void f1(T, U, V);
//	template <typename T> T f2(int &t);
	template <typename T> T f2(int &T);
//	template inline <typename T> T foo(T, unsigned int *);
	inline template <typename T> T foo(T, unsigned int *);
//	currect
	template <typename T> f4(T, T);		// return type: int
//	currect
	typedef char Ctype;
	template <typename Ctype> Ctype f5(Ctype a);	// hide typedef
