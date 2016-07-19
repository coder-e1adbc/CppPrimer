#include <memory>

using std::unique_ptr;

int main()
{
	unique_ptr<int> p1(new int(42)), p2;
	p2 = p1;	// error: use of deleted function operator=()

	return 0;
}
