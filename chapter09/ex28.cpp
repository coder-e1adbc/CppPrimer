#include <string>
#include <forward_list>

using std::string;
using std::forward_list;

forward_list<string>::iterator find_insert(forward_list<string> &flst, string str1, string str2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
		if (*curr == str1)
			return flst.insert_after(curr, str2);
		else
			prev = curr++;
	return flst.insert_after(prev, str2);
}
