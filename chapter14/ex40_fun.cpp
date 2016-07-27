#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "ex40.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stable_sort;
using std::find_if;
using std::for_each;
using std::sort;
using std::unique;

void elimDups(vector<string> &words);

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), SizeComp());
	auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
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

main()
{
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	biggies(words, 5);

	return 0;
}
