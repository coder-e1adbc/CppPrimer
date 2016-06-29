#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main(void)
{
	const int arr[] = {0, 1, 2, 3, 4};
	vector<int> vec(begin(arr), end(arr));
	
	return 0;
}

