#include <string>

using std::string;

void replace(string &s, string oldVal, string newVal)
{
	decltype(s.size()) pos(0), cur, cur_old;
	auto size_old = oldVal.size();
	auto size_new = newVal.size();

	while (pos != s.size())
	{
		cur = pos;
		cur_old = 0;
		while (cur != s.size() && cur_old != oldVal.size() && s[cur] == oldVal[cur_old])
			++cur, ++cur_old;
		if (cur_old == oldVal.size())
		{
			s.replace(pos, size_old, newVal);
			pos += size_new;
		}else
			++pos;
	}
}
