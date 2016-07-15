/* (a) *****************************************/
	vector<int> vec;
	list<int> lst;
	int i;

	while (cin >> i)
		lst.push_back(i);	
	copy(lst.cbegin(), lst.cend(), vec.begin());		// warning: vec is empty
//	copy(lst.cbegin(), lst.cend(), back_inserter(vec));

/* (b) *****************************************/
	vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
