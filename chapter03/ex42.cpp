#include <vector>
#include <iterator>

using std::vector;
using std::begin;
using std::end;

int main(void)
{
	const vector<int> vec{0, 1, 2, 3, 4};
	int arr[5];
	size_t size = end(arr) - begin(arr);
	for (size_t i = 0; i < size; ++i)
		arr[i] = vec[i];

	return 0;
}
