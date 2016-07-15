#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::front_inserter;
using std::back_inserter;
using std::inserter;

void print(const vector<int> &);

int main()
{
	vector<int> vec, vf, vb, vi;
	for (int i = 1; i != 10; ++i)
		vec.push_back(i);
//	copy(vec.cbegin(), vec.cend(), front_inserter(vf));		// vector not support push_front
	copy(vec.cbegin(), vec.cend(), back_inserter(vb));
	copy(vec.cbegin(), vec.cend(), inserter(vi, vi.begin()));
	
//	print(vf);
	print(vb);
	print(vi);

	return 0;
}

void print(const vector<int> &vec)
{
	for (auto const &val : vec)
		cout << val << ' ';
	cout << endl;
}
