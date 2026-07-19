#include <iostream>
#include <limits>



int main() {
	float a, b;
	std::cout << "Enter your first number: " << std::endl;
	std::cin >> a;

	while (std::cin.fail()) {
		std::cout << "ERROR: invalid syntax." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your first number: " << std::endl;
		std::cin >> a;
	}
	char opt;
	std::cout << "Choose one of the options: " << std::endl;
	std::cout << "+" << std::endl;
	std::cout << "-" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "/" << std::endl;
	std::cout << "%" << std::endl;
	std::cout << "^" << std::endl;
	std::cin >> opt;
	while (opt != '+' && opt != '-' && opt != '*' && opt != '/' && opt != '%' && opt != '^') {
			std::cout << "ERROR: invalid syntax." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Choose one of the options: " << std::endl;
			std::cout << "+" << std::endl;
			std::cout << "-" << std::endl;
			std::cout << "*" << std::endl;
			std::cout << "/" << std::endl;
			std::cout << "%" << std::endl;
			std::cout << "^" << std::endl;
			std::cin >> opt;
	}
	std::cout << "Enter your second number: " << std::endl;
	std::cin >> b;
	while (std::cin.fail()) {
		std::cout << "ERROR: invalid syntax." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your second number: " << std::endl;
		std::cin >> b;
	}
	switch (opt) {
	case '+':
		std::cout << "Result: " << a + b << std::endl;
		break;

	case '-':
		std::cout << "Result: " << a - b << std::endl;
		break;

	case '*':
		std::cout << "Result: " << a * b << std::endl;
		break;

	case '/':
		while (b == 0) {
			std::cout << "ERROR: invalid syntax or failed dividing by zero." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter your second number: " << std::endl;
			std::cin >> b;
		}
		std::cout << "Result: " << a / b << std::endl;
		break;

	case '%':
		while (b == 0) {
			std::cout << "ERROR: invalid syntax or failed dividing by zero." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter your second number: " << std::endl;
			std::cin >> b;
		}
		std::cout << "Result: " << fmod(a, b) << std::endl;
		break;

	case '^':
		std::cout << "Result: " << pow(a, b) << std::endl;
		break;
	}

	return 0;
}