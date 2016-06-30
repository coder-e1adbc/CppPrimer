vector<string>::iterator iter = vec.begin();

*iter++;			// *(iter++);
(*iter)++;			// illegal
*iter.empty();		// illegal
iter->empty();
++*iter;			// illegal
iter++->empty();
