#include <cstddef>

void* operator new(std::size_t);
void operator delete(void *) noexcept;
