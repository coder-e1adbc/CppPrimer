mulitset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

mulitset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::const_iterator mset_it = bookstore.begin();
