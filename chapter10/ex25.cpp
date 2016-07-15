#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stable_sort;
using std::partition;
using std::placeholders::_1;
using std::for_each;
using std::sort;
using std::unique;

void elimDups(vector<string> &words);
bool chack_size(const string &, string::size_type);

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
	auto wc = partition(words.begin(), words.end(), bind(chack_size, _1, sz));
	auto count = words.end() - wc;
	cout << count << " word" << (count > 1 ? "s" : "") << " of length " << sz << " or longer." << endl;
	for_each(wc, words.end(), [](string &s) { cout << s << ' ' ;});
	cout << endl;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

inline bool chack_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

main()
{
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(words, 5);

	return 0;
}
