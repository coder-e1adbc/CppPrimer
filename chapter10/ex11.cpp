#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::stable_sort;

void elimDups(vector<string> &);
bool isShorter(const string &, const string &);
void print(vector<string> &);

int main()
{
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	print(words);

	return 0;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
