#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

class Screen;
class Windows_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;

	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;	//	can't use {Screen(25, 80)};
};

class Screen {
friend void Windows_mgr::clear(ScreenIndex);
public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) { }

	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const { return contents[ht * width + wd]; }
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos row, pos col, char ch);
	Screen& display(std::ostream &);
	const Screen& display(std::ostream &) const;
	pos size() const;
	static const std::string Screen::*data() { return &Screen::contents; }
private:
	void do_display(std::ostream &os) const { os << contents; }

	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline void Windows_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos row, pos col, char ch)
{
	contents[row * width + col] = ch;
	return *this;
}

inline Screen& Screen::display(std::ostream &os)
{
	do_display(os);
	return *this;
}

inline const Screen& Screen::display(std::ostream &os) const
{
	do_display(os);
	return *this;
}

inline Screen::pos Screen::size() const
{
	return height * width;
}
#endif
