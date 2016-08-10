#include <bitset>
#include <string>

template <std::size_t N> class Answer {
public:
	Answer() = default;
	Answer(unsigned u):
		answer(u) { }
	Answer(std::string s):
		answer(s) { }
	void upgrade(std::size_t index, bool a)
		{ answer.set(index, a); }
private:
	std::bitset<N> answer;
};
