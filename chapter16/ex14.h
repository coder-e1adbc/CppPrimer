#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

template <unsigned H, unsigned W> class Screen {
public:
	using pos = std::string::size_type;
	Screen(char c = ' '):
		contents(H * W, c) { }
	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const { return contents[ht * width + wd]; }
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos row, pos col, char ch);
	Screen& display(std::ostream &);
	const Screen& display(std::ostream &) const;
	pos size() const
		{ return height * width; }

private:
	void do_display(std::ostream &os) const { os << contents; }
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

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::display(std::ostream &os)
{
	do_display(os);
	return *this;
}

template <unsigned H, unsigned W>
inline const Screen<H, W> & Screen<H, W>::display(std::ostream &os) const
{
	do_display(os);
	return *this;
}

#endif
