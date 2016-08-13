vector<Sales_data>::iterator find_above(vector<Sales_data> &vec, double price)
{
	return find_if(vec.cbegin(), vec.cend(),
			[price](Sales_data &s) { return s.avg_price() > price; });
}
