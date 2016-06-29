constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)	// error: array begin with 0 and end with size-1
	ia[ix] = ix;
