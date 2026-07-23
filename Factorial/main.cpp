#include <iostream>
#include <limits>

uint32_t factorial(uint32_t n) {
	if (n == 0) return 1;
	else return n * factorial(n - 1);
}
	
int main()
{
	int a;
	uint32_t ua;
	std::cout << "Enter any natural number: ";
	std::cin >> a;
	while (std::cin.fail() || a < 0) {
		std::cerr << "ERROR: invalid symbol or out of scope" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter any natural number: ";
		std::cin >> a;
	}
	ua = static_cast<uint32_t>(a);
	if (factorial(ua) == 0) {
		std::cout << "The factorial of " << ua << " is way too large";
	}
	else {
		std::cout << "Factorial of " << ua << " is " << factorial(ua) << std::endl;
	}
	return 0;
}