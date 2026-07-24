#include <iostream>
#include <limits>

float max(float arr[], int n) {
	float m = *arr;
	for (int i = 0; i < n; ++i) {
		if (m < arr[i]) {
			m = arr[i];
		}
	}
	return m;
}

float min(float arr[], int n) {
	float m = *arr;
	for (int i = 0; i < n; ++i) {
		if (m > arr[i]) {
			m = arr[i];
		}
	}
	return m;
}
float sum(float arr[], int n) {
	float sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
	}
	return sum;
}
float mean(float arr[], int n) {
	return sum(arr, n) / n;
}
float var(float arr[], int n) {
	float m = mean(arr, n);
	float sum;
	for (int i = 0; i < n; ++i) {
		sum = pow(arr[i] - m, 2);
	}
	return sum / n;
}
float stdDev(float arr[], int n) {
	return sqrtf(var(arr, n));
}


int main()
{
	int n{};

	std::cout << "Enter the number of elements of the array: ";
	std::cin >> n;
	while (std::cin.fail() || n <= 0) {
		std::cerr << "ERROR: Invalid symbols or out of the scope" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the number of elements of the array: ";
		std::cin >> n;
	}
	float* arr = new float[n];

	for (int i = 0; i < n; ++i) {
		float tempValue;
		std::cout << "Enter the value of " << i << " element of the array: ";
		std::cin >> tempValue;
		while (std::cin.fail()) {
			std::cerr << "ERROR: Invalid symbols or out of the scope" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter the value of " << i << " element of the array: ";
			std::cin >> tempValue;
		}
		arr[i] = tempValue;
	}

	std::cout << "Your array looks like this: ";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;


	std::cout << "Max value: " << max(arr, n) << std::endl;
	std::cout << "Min value: " << min(arr, n) << std::endl;
	std::cout << "Sum of values: " << sum(arr, n) << std::endl;
	std::cout << "Mean value of the array: " << mean(arr, n) << std::endl;
	std::cout << "Variance of the values:  " << var(arr, n) << std::endl;
	std::cout << "The standard deviation of the values in the array: " << stdDev(arr, n) << std::endl;
	delete[] arr;
	return 0;
}