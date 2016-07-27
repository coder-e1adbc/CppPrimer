class SizeComp {
public:
	SizeComp(size_t n = 0):
		sz(n) { }
	bool operator()(const std::string &s1, const std::string &s2) const
		{ return s1.size() < s2.size(); }
	bool operator()(const std::string &s) const
		{ return s.size() >= sz; }
private:
	size_t sz;
};
