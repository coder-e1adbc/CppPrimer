struct Matches {
	Matches() = default;
	Matches(vector<Sales_data>::size_type i,
			vector<Sales_data>::const_iterator b,
            vector<Sales_data>::const_iterator e):
		index(i), beg(b), end(e) { }

	vector<Sales_data>::size_type index;
    vector<Sales_data>::const_iterator beg;
	vector<Sales_data>::const_iterator end;
}
vector<Matches> findBook(const vector<vector<Sales_data>> &files,
		const string &book)
{
	vector<Matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.emplace(it - files.cbegin(), found.first, found.second);
	}
	return ret;
}
