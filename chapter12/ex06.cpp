#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>* make_vector();
void read(vector<int> *);
void print(const vector<int> *);

int main()
{
	auto vp = make_vector();
	read(vp);
	print(vp);
	
	delete vp;

	return 0;
}

vector<int>* make_vector()
{
	return new vector<int>;
}

void read(vector<int> *p)
{
	int val;
	while (cin >> val)
		p->push_back(val);
}

void print(const vector<int> *p)
{
	for (auto &val : *p)
		cout << val << ' ' ;
}

