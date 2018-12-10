#include <map>
std::map<int, int> x;

__attribute__((visibility("default")))
extern "C" int foo() {
	x[42] = 32;
	int i = 0;
	for (auto y: x) {
		i++;
		// prevent browser from hanging!
		if (i > 10) break;
	}
	// returns 10 instead of 1
	return i;
}