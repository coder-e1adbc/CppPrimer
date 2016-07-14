#include <string>

using std::string;

void replace(string &s, string oldVal, string newVal)
{
	auto pos = s.begin();
	decltype(s.begin()) iter;
	decltype(oldVal.cbegin()) iter2;
	auto size = newVal.size();
	while (pos != s.end())
	{
		iter = pos;
		iter2 = oldVal.cbegin();
		while (iter != s.end() && iter2 != oldVal.cend() && *iter == *iter2)
			++iter, ++iter2;
		if (iter2 == oldVal.cend())
		{
			pos = s.erase(pos, iter);
			pos = s.insert(pos, newVal.cbegin(), newVal.cend());
			pos += size;
		}else
			++pos;
	}
}

