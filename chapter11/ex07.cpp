#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

using Map = map<string, vector<string>>;

void add_family(Map &, const string &, const string & = "");
void add_member(Map &, const string &, const string &);

void add_family(Map &mp, const string &family, const string &member)
{
	add_member(mp, family, member);
}

void add_member(Map &mp, const string &family, const string &member)
{
	mp[family].push_back(member);
}
