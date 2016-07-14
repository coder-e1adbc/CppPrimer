vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
auto begin = v.begin();
while (begin != v.end())
{
	++begin;
	v.insert(begin, 42);	// error: insert operator make begin iterator invalid
	++begin;
}
