#ifndef STRING_H
#define STRING_H

#include <memory>
#include <utility>
#include <iostream>

class String {
friend std::ostream& operator<<(std::ostream &, String &);
friend bool operator==(const String &, const String &);
friend bool operator!=(const String &, const String &);
friend bool operator<(const String &, const String &);
friend bool operator<=(const String &, const String &);
friend bool operator>(const String &, const String &);
friend bool operator>=(const String &, const String &);
public:
	String():
		bg(nullptr), ed(nullptr) { }
	String(const char *);
	String(const String &);
	String(String &&) noexcept;
	String& operator=(const String &);
	String& operator=(String &&);
	~String();

	char* begin() const { return bg; }
	char* end() const { return ed; }
	size_t size() const { return ed - bg; }

private:
	static std::allocator<char> alloc;
	std::pair<char *, char *> alloc_n_copy(const char *, const char *);
	void free();
	char *bg;
	char *ed;
};

std::ostream& operator<<(std::ostream &, String &);
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>(const String &, const String &);
bool operator>=(const String &, const String &);

#endif
