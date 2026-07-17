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

	if (age < 25) std::cout << "Hello, " << name << ". You are only " << age << " years old." << std::endl;
	if (age < 50 && age >= 25) std::cout << "Hello, " << name << ". You are already " << age << " years old." << std::endl;
	if (age >= 50) std::cout << "Hello, " << name << ". You are very wise for your age." << std::endl;
	return 0;
}