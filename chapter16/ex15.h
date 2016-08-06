#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

template <unsigned H, unsigned W> class Screen {
friend std::istream& operator>>(std::istream &, Screen<H, W>);
friend std::ostream& operator<<(std::ostream &, Screen<H, W>);
public:
	using pos = std::string::size_type;
	Screen(char c = ' '):
		contents(H * W, c) { }
	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const { return contents[ht * width + wd]; }
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos row, pos col, char ch);
	pos size() const
		{ return height * width; }

private:
	pos cursor = 0;
	pos height = H, width = W;
	std::string contents;
};

template<unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(pos row, pos col, char ch)
{
	contents[row * width + col] = ch;
	return *this;
}

std::istream& operator>>(std::istream &is, Screen<H, W> &s)
{
	is >> s.contents;
	if (s.contents.size() > s.size())
		s.contents.erase(s.size());
	else
		s.contents.append(s.size() - s.contents.size(), ' ');
	return is;
}

std::ostream& operator<<(std::ostream &os, const Screen<H, W> &s)
{
	os << s.contents;
	return os;
}

#endif
