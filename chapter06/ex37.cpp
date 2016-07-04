#include <string>

using std::string;

using str_arr_10 = string[10];
str_arr_10* func();

auto func() -> string(*)[10];

string str[10];
decltype(str)* func();
