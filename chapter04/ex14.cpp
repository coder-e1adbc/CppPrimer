int main(void)
{
	int i{0};
	if (42 = i);	// error: 42 is not a lvalue
	if (i = 42);	// warning: always true!

	return 0;
}
