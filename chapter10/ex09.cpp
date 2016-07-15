#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::unique;

void print(vector<string> &);

void elimDups(vector<string> &words)
{
	print(words);
	sort(words.begin(), words.end());
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	words.erase(end_unique, words.end());
	print(words);
}

void print(vector<string> &vec)
{
	for (const auto &s : vec)
		cout << s << ' ' ;
	cout << endl;
}
