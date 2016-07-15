#include "Sales_data.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::sort;
using std::vector;

void printvec(vector<Sales_data> &);

int main()
{
	ifstream in("book_sales");
	Sales_data item;
	vector<Sales_data> vec;
	while (read(in, item))
		vec.push_back(item);

	printvec(vec);
	cout << endl;
	sort(vec.begin(), vec.end(), [](Sales_data &item1, Sales_data &item2) { return item1.isbn() < item2.isbn(); });
	printvec(vec);

	return 0;
}

void printvec(vector<Sales_data> &vec)
{
	for (const auto &item : vec)
		print(cout, item) << endl;
}
