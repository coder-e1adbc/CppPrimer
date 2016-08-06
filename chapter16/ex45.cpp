template <typename T> void g(T &&val)
{
	vector<T> v;
}

int i = 42;
g(42);	// T: int		calls vector<int> legal
g(i);	// T: int &		calls vector<int &> error!
