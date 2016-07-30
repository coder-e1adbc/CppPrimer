#include "ex27.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::string;
using std::size_t;

int main()
{
	vector<Quote> vec;
	vec.push_back(Bulk_quote("345", 45, 3, .15));
	vec.push_back(Bulk_quote("678", 55, 5, .25));
	auto total = 0.0;
	for (const auto &q : vec)
		total += q.net_price(10);
	cout << total << endl;

	return 0;
}
	
