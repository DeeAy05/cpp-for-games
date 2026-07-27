#include <iostream>
#include <limits>

constexpr float PI = 3.141592653f;

class Shape {
public:
	virtual ~Shape() = default;

	virtual std::string getName() const = 0;
	virtual float getArea() const = 0;
	virtual float getPerimeter() const = 0;
};

class Circle : public Shape {
private: 
	float r;
public:
	explicit Circle(float r) : r{ r } {}

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
};

class Square : public Shape {
private:
	float l;
public:
	explicit Square(float l) : l{ l } {}

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
};

class Rectangle : public Shape {
private:
	float w, h;
public:
	explicit Rectangle(float w, float h) : w{ w }, h{ h } {}

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
};

class Triangle : public Shape {
private:
	float b, h;
public:
	explicit Triangle(float b, float h) : b{ b }, h{ h } {}

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
};

std::string Circle::getName() const
{
	return "Circle";
	// TODO: insert return statement here
}

float Circle::getArea() const
{
	return PI * r * r;
}

float Circle::getPerimeter() const
{
	return 2 * PI * r;
}

std::string Square::getName() const
{
	return "Square";
}

float Square::getArea() const
{
	return l * l;
}

float Square::getPerimeter() const
{
	return 4 * l;
}

std::string Rectangle::getName() const
{
	return "Rectangle";
}

float Rectangle::getArea() const
{
	return w * h;
}

float Rectangle::getPerimeter() const
{
	return 2 * w + 2 * h;
}

std::string Triangle::getName() const
{
	return "Triangle";
}

float Triangle::getArea() const
{
	return b * h / 2;
}

float Triangle::getPerimeter() const
{
	return b + h + sqrtf(b * b + h * h);
}

void userInput(float& n, const char* c) {
	std::cout << c;
	std::cin >> n;
	while (std::cin.fail() || n <= 0) {
		std::cerr << "Invalid symbols or out of the scope"  << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << c;
		std::cin >> n;
	}
}

int main()
{
	Shape* array[4];
	float c_r, s_l, r_w, r_h, t_b, t_h;
	userInput(c_r, "Enter the radius of the circle: ");
	array[0] = new Circle(c_r);
	userInput(s_l, "Enter the length of the square: ");
	array[1] = new Square(s_l);
	userInput(r_w, "Enter the width of the rectangle: ");
	userInput(r_h, "Enter the height of the rectangle: ");
	array[2] = new Rectangle(r_w, r_h);
	userInput(t_b, "Enter the base of the triangle: ");
	userInput(t_h, "Enter the height of the triangle: ");
	array[3] = new Triangle(t_b, t_h);
	
	for (auto s : array) {
		std::cout << "The name: " << s->getName() << std::endl;
		std::cout << "The area: " << s->getArea() << std::endl;
		std::cout << "The perimeter: " << s->getPerimeter() << std::endl;
	}


	for (auto s : array) {
		delete s;
	}
	return 0;
}