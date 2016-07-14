// c.size() == 1
if (!c.empty())
{
	auto val = *c.begin(), val2 = c.front();	// val = c[0], val2 = c[0]
	auto last = c.end();
	auto val3 = *(--last);						// val3 = c[0]
	auto val4 = c.back();						// val4 = c[0]
}
