map<string, size_t> word_count;
string word;

while (cin >> word)
	++word_count.insert({word, 0}).first->second;	// the same as ex20
