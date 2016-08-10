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

template <std::size_t N> class Grade {
public:
	Grade() = delete;
	Grade(const Answer<N> &a):
		correct(a) { }
	double score(const Answer<N> a)
		{ return (a & correct).count() * 100.0 / N; }
private:
	const Answer<N> correct;
};
