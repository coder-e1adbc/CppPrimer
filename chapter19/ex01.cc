#include "ex01.h"
using std::size_t;

#include <new>
using std::bad_alloc;

#include <cstdlib>
using std::malloc;
using std::free;

void* operator new(size_t size) {
	if (void *mem = malloc(size))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void *mem) noexcept {
	free(mem);
}
