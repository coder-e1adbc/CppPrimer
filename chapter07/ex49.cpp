Sales_data i;
std::string s;
i.combine(s);

Sales_data& combine(Sales_data);	// Sales_data tmp(s), i.combine(tmp);
Sales_data& combine(Sales_data &);	// error: non-const reference can't refer to temp object.
Sales_data& combine(const Sales_data &);	// const Sales_data &tmp(s), i.combine(tmp);
