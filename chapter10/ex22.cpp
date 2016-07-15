#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stable_partition;
using std::count_if;
using std::placeholders::_1;
using std::for_each;
using std::sort;
using std::unique;

void elimDups(vector<string> &words);
bool chack_size(const string &s, string::size_type sz);

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() > sz; });
	auto count = count_if(words.cbegin(), words.cend(), bind(chack_size, _1, sz));
	cout << count << " word" << (count > 1 ? "s" : "") << " of length " << sz << " or less." << endl;
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
	return s.size() <= sz;
}

main()
{
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(words, 6);

	return 0;
}
