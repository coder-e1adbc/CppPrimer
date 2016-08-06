template <typename P, typename T>
P find(const P &beg, const P &end, const T &val)
{
	P it(beg);
	while (it != end && *it != val)
		++it;
	return it;
}
