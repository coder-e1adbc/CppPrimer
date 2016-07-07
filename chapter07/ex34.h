#include <string>

int height;

class Screen {
public:
	void dummy_fcn(pos height) { cursor = width * height; }	// error: 'pos' has not been declared
private:
	pos cursor = 0;											// error: 'pos' has not been declared
	pos height = 0, width = 0;								// error: 'pos' has not been declared

	typedef std::string::size_type pos;
};
