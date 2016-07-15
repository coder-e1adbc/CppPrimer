#include <vector>
#include <string>

using std::vector;
using std::string;

void elimDups(vector<string> &);

int main()
{
	vector<string> words{ "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
	elimDups(words);

	return 0;
}
