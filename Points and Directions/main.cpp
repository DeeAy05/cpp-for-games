#include "Direction.hpp"
#include "Point.h"



int main()
{
	Point p1{ 10, 3 };
	Direction d1{ 1, 1 };
	Point p2 = p1 - d1;
	Point p3 = p1 + d1;
	Direction d2 = p3 - p2;
	assert(p2.x == 9 && p2.y == 2);
	assert(d2.x == 2 && d2.y == 2);
	return 0;

	Direction d3{ 3, 3 };
	Direction d4{ 2, 1 };
	Direction d5 = d3 - d4;
	assert(d5.x == 1 && d5.y == 2);
	Direction d6 = d3 + d4;
	assert(d6.x == 5 && d6.y == 4);

	Direction d7 = 4 * d3;
	assert(d7.x == 12 && d7.y == 12);
}