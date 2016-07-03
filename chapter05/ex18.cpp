/*************************************/
	do													// do {
		int v1, v2;
		cout << "Please enter two numbers to sum:" ;
		if (cin >> v1 >> v2)
			cout << "The sum is: " << v1 + v2 << endl;
	while (cin);										// } while(cin);

/*************************************/
											// int ival;
	do {
		//...
	} while (int ival = get_response());	// while (ival = get_response());

/*************************************/
										// int ival;
	do {		
		int ival = get_response();		// ival = get_response();
	} while (ival);
