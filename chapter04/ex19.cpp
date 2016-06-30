	int *ptr;
	vector<int> vec;
	int ival;

	ptr != 0 && *ptr++					// ptr != 0 && *ptr != 0, ++ptr
	ival++ && ival						// ival != 0 && ival != -1
	vec[ival++] <= vec[ival]			// warning: undefined 
//	vec[ival] <= vec[ival + 1], ++ival
