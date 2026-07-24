#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::remove_if(v.begin(), v.end(), [](int x) {
		return x % 2 != 0;
		});



	for (auto i : v) {
		std::cout << i << " ";
	}

	return 0;
}