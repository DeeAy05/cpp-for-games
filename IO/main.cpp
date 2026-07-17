#include <iostream>
#include <string>
#include <limits>

int main() {
	std::string name;
	int age;
	std::cout << "Enter your name:" << std::endl;
	std::cin >> name;
	std::cout << "Enter your age:" << std::endl;
	std::cin >> age;

	while (std::cin.fail() || age < 0) {
		std::cout << "ERROR: Invalid symbols were entered" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your age:" << std::endl;
		std::cin >> age;
	}
	std::cout << "Hello, " << name << ". You are " << age << " years old." << std::endl;
	return 0;
}