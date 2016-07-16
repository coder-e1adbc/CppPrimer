#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

using Map = map<string, vector<pair<string, string>>>;

void add_family(Map &, const string &, const string & = "", const string & = "");
void add_member(Map &, const string &, const string &, const string & = "");

void add_family(Map &mp, const string &family, const string &member, const string &birthday)
{
	add_member(mp, family, member, birthday);
}

void add_member(Map &mp, const string &family, const string &member, const string &birthday)
{
	mp[family].push_back({member, birthday});
}
