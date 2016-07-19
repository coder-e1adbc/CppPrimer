#include <iostream>
#include <vector>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::make_shared;
using std::shared_ptr;

shared_ptr<vector<int>> make_vector();
void read(shared_ptr<vector<int>>);
void print(const shared_ptr<vector<int>>);

int main()
{
	auto vp = make_vector();
	read(vp);
	print(vp);

	return 0;
}

shared_ptr<vector<int>> make_vector()
{
	return make_shared<vector<int>>();
}

void read(shared_ptr<vector<int>> p)
{
	int val;
	while (cin >> val)
		p->push_back(val);
}

void print(const shared_ptr<vector<int>> p)
{
	for (auto &val : *p)
		cout << val << ' ' ;
}

