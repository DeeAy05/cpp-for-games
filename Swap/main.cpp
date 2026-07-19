#include <iostream>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void swapByReference(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int a = 3, b = 5;
	std::cout << "Value of a: " << a << " and b: " << b << std::endl;

	swap(&a, &b);
	std::cout << "Value of a: " << a << " and b: " << b << std::endl;

	swapByReference(a, b);
	std::cout << "Value of a: " << a << " and b: " << b << std::endl;
	return 0;
}