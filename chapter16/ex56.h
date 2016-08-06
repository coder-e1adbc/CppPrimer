#include <iostream>
#include "ex48.h"
#include "ex53.h"

template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}
