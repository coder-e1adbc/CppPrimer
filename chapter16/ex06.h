template <typename T, unsigned N>
T* begin(T (&arr)[N])
{
	return arr;
}

template <typename T, unsigned N>
T* end(T (&arr)[N])
{
	return arr + N;
}
