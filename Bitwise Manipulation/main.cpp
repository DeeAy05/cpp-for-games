#include <iostream>
#include <limits>
#include <bitset>
int main()
{
	int a;
	std::cout << "Enter an integer in the range (0-255): ";
	std::cin >> a;

	while (std::cin.fail() || a < 0 || a > 255)
	{
		std::cerr << "ERROR: invalid symbols or out of scope" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter an integer in the range (0-255): ";
		std::cin >> a;
	}
	uint8_t ua = static_cast<uint8_t>(a);

	std::cout << "Enter a bit position in the range (0-7): ";
	std::cin >> a;

	while (std::cin.fail() || a < 0 || a > 7)
	{
		std::cerr << "ERROR: invalid symbols or out of scope" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter a bit position in the range (0-7): ";
		std::cin >> a;
	}

	std::cout << "Number in binary: " << std::bitset<8>(ua) << std::endl;
	std::cout << "Number of bits that are set: " << std::bitset<8>(ua).count() << std::endl;
	if (std::bitset<8> (ua)[a] == 1) {
		std::cout << "Bit " << a << " is set: true." << std::endl;
	}
	else {
		std::cout << "Bit " << a << " is set: false." << std::endl;
	}
	bool bVal;
	std::cout << "Set the new value of " << a << " bit (0 or 1): ";
	std::cin >> bVal;

	while (std::cin.fail()) {
		std::cerr << "ERROR: invalid symbol or out of scope" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Set the new value of " << a << " bit (0 or 1): ";
		std::cin >> bVal;
	}
	ua = std::bitset<8>(ua).set(a, bVal).to_ulong();
	std::cout << "New value in decimal: " << static_cast<int>(ua) << std::endl;
	std::cout << "New value in binary: " << std::bitset<8>(ua) << std::endl;

	ua = std::bitset<8>(ua).reset(a).to_ulong();
	std::cout << "New value after resetting in decimal: " << static_cast<int>(ua) << std::endl;
	std::cout << "New value after resetting in binary: " << std::bitset<8>(ua) << std::endl;
	
	ua = std::bitset<8>(ua).flip(a).to_ulong();
	std::cout << "New value after inverting in decimal: " << static_cast<int>(ua) << std::endl;
	std::cout << "New value after inverting in binary: " << std::bitset<8>(ua) << std::endl;
	
	//ua = ua << a;
	std::cout << "Value after left shifting by "<< a << " bit in decimal: " << std::bitset<8>(ua << a).to_ulong() << std::endl;
	std::cout << "Value after left shifting by "<< a << " bit in binary: " << std::bitset<8>(ua << a) << std::endl;

	std::cout << "Value after right shifting by " << a << " bit in decimal: " << std::bitset<8>(ua >> a).to_ulong() << std::endl;
	std::cout << "Value after right shifting by " << a << " bit in binary: " << std::bitset<8>(ua >> a) << std::endl;
	return 0;
}