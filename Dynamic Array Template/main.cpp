#include "Array.hpp"
#include <utility>
#include <iostream>
#include <cassert>
#include <numeric>
int main()
{
	Array<int> arr;
	std::cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << std::endl;
	Array<int> arr1(3, 10);
	std::cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << *(arr1.data() + i) << std::endl;
	}
	Array<int> arr2(arr1);
	for (int i = 0; i < 3; ++i) {
		assert(*(arr1.data() + i) == *(arr2.data() + i));
	}
	std::cout << "Copy constructor is successful" << std::endl;

	Array<int> arr3(std::move(arr2));
	for (int i = 0; i < 3; ++i) {
		std::cout << *(arr3.data() + i) << std::endl;
	}
	assert(arr2.isEmpty());
	std::cout << "Move constructor is successful" << std::endl;

	arr = arr3;
	for (int i = 0; i < 3; ++i) {
		assert(*(arr.data() + i) == *(arr3.data() + i));
	}
	std::cout << "Copy assignment is successful" << std::endl;

	arr = std::move(arr3);
	for (int i = 0; i < 3; ++i) {
		std::cout << *(arr.data() + i) << std::endl;
	}
	assert(arr3.isEmpty());
	std::cout << "Move assignment is successful" << std::endl;

	auto it1 = arr.begin();
	assert(it1 == arr.begin());

	auto it2 = arr.end();
	assert(it2 == arr.end());
	int i = 1;
	arr.add(i);
	arr.add(13);
	for (auto i : arr) {
		std::cout << i << std::endl;
	}
	int sum = std::accumulate(arr.begin(), arr.end(), 0);
	std::cout << sum;
}