int count_calls()
{
	static size_t cnt = 0;

	return cnt++;
}
