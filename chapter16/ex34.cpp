template <class T> int compare(const T&, const T&);

// illegal. can't instantiate compare(const char[3], const char[6])
compare("hi", "world");
// legal. calls compare(const char[4], const char[4]);
compare("bye", "dad");
