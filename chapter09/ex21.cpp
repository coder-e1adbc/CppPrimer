vector<int> vec;
auto iter = vec.begin();
while (cin >> word)
	iter = vec.insert(iter, word);
