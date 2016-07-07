#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {

public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c = ' ') : height(ht), width(wd), contents(ht * wd, c) { }

	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd) const { return contents[ht * width + wd]; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

#endif
