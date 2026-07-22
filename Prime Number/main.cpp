#include <iostream>

int main() {
	int n;
	bool isPrime;
	std::cout << "Enter any natural number: ";
	std::cin >> n;

	while (std::cin.fail() || n <= 0) {
		std::cerr << "ERROR: invalid symbols or out of scope." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter any natural number: ";
		std::cin >> n;
	}

	uint32_t number = static_cast<uint32_t>(n);

	if (number == 1) {
		std::cout << number << " is not a prime number";
		return 0;
	}

	for (int i = 1; i < number; ++i) {
		if (number % i == 0 && i != 1) {
			isPrime = false;
			break;
		}
		else isPrime = true;
	}
	if (isPrime) std::cout << number << " is a prime number";
	else std::cout << number << " is not a prime number";

	return 0;
}