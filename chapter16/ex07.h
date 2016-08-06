template <typename T, size_t N>
constexpr size_t size(const T (&array)[N])
{
	return N;
}
