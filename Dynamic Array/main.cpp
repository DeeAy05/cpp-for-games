#include <iostream>
#include <limits>


int main()
{
	int arraySize;
	int* max{ nullptr };
	int* min{ nullptr };
	float sum = 0.0f;
	std::cout << "Enter the size of array (1 to 10): ";
	std::cin >> arraySize;
	while (std::cin.fail() || arraySize <= 0 || arraySize > 10) {
		std::cout << "Error occured: invalid symbol" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the size of array (1 to 10): ";
		std::cin >> arraySize;
	}
	int* array = new int[arraySize];

	for (int i = 0; i < arraySize; i++) {
		std::cout << "Enter the " << i << " element of an array (integers only): ";
		std::cin >> array[i];
		while (std::cin.fail()) {
			std::cout << "Error occured: invalid symbol" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter the " << i << " element of an array (integers only): ";
			std::cin >> array[i];
		}
		sum += array[i];
		if (!max) {
			max = &array[i];
		}
		if (!min) {
			min = &array[i];
		}

		if (*min > array[i]) {
			min = &array[i];
		}
		if (*max < array[i]) {
			max = &array[i];
		}
	}
	std::cout << "The maximum value entered: " << *max << std::endl;
	std::cout << "The minumum value entered: " << *min << std::endl;
	std::cout << "The average value entered: " << sum / arraySize << std::endl;
	delete[] array;
	return 0;
}