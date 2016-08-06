template <typename T1, typename T2>
auto sum(T1 lhs, T2 rhs) -> decltype(lhs + rhs)
{
	return lhs + rhs;
}
