#include <iostream>
#include <limits>

const float PI = 3.141592653f;

char numToC(char &s) {
	int a = s - '0';
	if (a >= 1 && a <= 4) {
		switch (a) {
		case 1:
			return s = 'C';
		case 2:
			return s = 'S';
		case 3:
			return s = 'R';
		case 4:
			return s = 'T';
		default:
			break;
		}
	}
}

void shapePrompt(char &s) {
	std::cout << "Choose your shape: " << std::endl;
	std::cout << "1. Circle (C)" << std::endl;
	std::cout << "2. Square (S)" << std::endl;
	std::cout << "3. Rectangle (R)" << std::endl;
	std::cout << "4. Triangle (T)" << std::endl;
	std::cin >> s;
	numToC(s);
}

int intUserInput(int& num, const char* prompt) {
	std::cout << prompt;
	std::cin >> num;

	while (std::cin.fail()) {
		std::cerr << "ERROR: invalid symbols" << std::endl;;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << prompt;
		std::cin >> num;
	}
	return num;
}

int main() {
	int r{}, s{}, w{}, h{}, b{};
	char shape;
	shapePrompt(shape);

	while (std::cin.fail() || shape != 'C' && shape != 'S' && shape != 'R' && shape != 'T') {
		std::cerr << "ERROR: invalid symbols or out of scope." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		shapePrompt(shape);
	}
	switch (shape){
		case 'C':
			intUserInput(r, "Enter the radius of the circle: ");
			std::cout << "The circumference of the circle: " << 2 * PI * r << std::endl;
			std::cout << "The area of the circle: " << PI * r * r << std::endl;
			break;
		case 'S':
			intUserInput(s, "Enter the length of the side: ");
			std::cout << "The perimeter of the square: " << 4 * s << std::endl;
			std::cout << "The area of the square: " << s * s << std::endl;
			break;
		case 'R':
			intUserInput(w, "Enter the width of the rectangle: ");
			intUserInput(h, "Enter the height of the rectangle: ");
			std::cout << "The perimeter of the rectangle: " << 2 * w + 2 * h << std::endl;
			std::cout << "The area of the rectangle: " << w * h << std::endl;
			break;
		case 'T':
			intUserInput(b, "Enter the base of the triangle: ");
			intUserInput(h, "Enter the height of the triangle: ");
			std::cout << "The perimeter of the right triangle: " << b + h + sqrt(b * b + h * h) << std::endl;
			std::cout << "The area of the right triangle: " << b * h / 2 << std::endl;
			break;
	}

	return 0;
}