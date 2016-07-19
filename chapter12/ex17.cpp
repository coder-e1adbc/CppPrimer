#include <memory>

using std::unique_ptr;

int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;

IntP p0(ix);				// error
IntP p1(pi);				// error: will delete a memory which is not allocated by new
IntP p2(pi2);				// correct
IntP p3(&ix);				// the same as p1
IntP p4(new int(2048));		// correct
IntP p5(p2.get());			// warning: now p2 and p5 are both point to 2048
							// error: delete will be called twice by p2 and p5

int main()
{
	return 0;
}
