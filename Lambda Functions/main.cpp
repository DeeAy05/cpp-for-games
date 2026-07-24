#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	auto cleanup = std::remove_if(v.begin(), v.end(), [](int x) {
		return x % 2 != 0;
		});


	v.erase(cleanup, v.end());

	for (auto i : v) {
		std::cout << i << " ";
	}

	return 0;
}