#include <iostream>
#include <limits>



int main() {
	int a, b;
	std::cout << "Enter your first number: " << std::endl;
	std::cin >> a;
	
	while (std::cin.fail()) {
		std::cout << "ERROR: invalid syntax." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your first number: " << std::endl;
		std::cin >> a;
	}
	int opt;
	std::cout << "Choose one of the options: " << std::endl;
	std::cout << "1. Add (+)" << std::endl;
	std::cout << "2. Subtract (-)" << std::endl;
	std::cout << "3. Multiply (*)" << std::endl;
	std::cout << "4. Divide (/)" << std::endl;
	std::cin >> opt;
	while (std::cin.fail() || (opt > 4 || opt < 1)) {
		std::cout << "ERROR: invalid syntax." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Choose one of the options: " << std::endl;
		std::cout << "1. Add (+)" << std::endl;
		std::cout << "2. Subtract (-)" << std::endl;
		std::cout << "3. Multiply (*)" << std::endl;
		std::cout << "4. Divide (/)" << std::endl;
		std::cin >> opt;
	}
	switch (opt) {
		case 1:
			std::cout << "Enter your second number: " << std::endl;
			std::cin >> b;
			while (std::cin.fail()) {
				std::cout << "ERROR: invalid syntax." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter your second number: " << std::endl;
				std::cin >> b;
			}
			std::cout << "Result: " << a+b << std::endl;
			break;
		case 2:
			std::cout << "Enter your second number: " << std::endl;
			std::cin >> b;
			while (std::cin.fail()) {
				std::cout << "ERROR: invalid syntax." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter your second number: " << std::endl;
				std::cin >> b;
			}
			std::cout << "Result: " << a - b << std::endl;
			break;
		case 3:
			std::cout << "Enter your second number: " << std::endl;
			std::cin >> b;
			while (std::cin.fail()) {
				std::cout << "ERROR: invalid syntax." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter your second number: " << std::endl;
				std::cin >> b;
			}
			std::cout << "Result: " << a * b << std::endl;
			break;
		case 4:
			std::cout << "Enter your second number: " << std::endl;
			std::cin >> b;
			while (std::cin.fail() || b == 0) {
				std::cout << "ERROR: invalid syntax or failed dividing by zero." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter your second number: " << std::endl;
				std::cin >> b;
			}
			std::cout << "Result: " << static_cast<double>(a)/ static_cast<double>(b) << std::endl;
			break;
	}

	return 0;
}