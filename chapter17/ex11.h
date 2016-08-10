#include <bitset>
#include <string>

template <std::size_t N> class Answer {
public:
	Answer() = default;
	Answer(unsigned u):
		answer(u) { }
	Answer(std::string s):
		answer(s) { }
private:
	std::bitset<N> answer;
};
