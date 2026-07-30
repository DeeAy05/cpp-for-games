#include "Point.h"

Point Point::operator+(const Direction& rhs) const
{
    return { x + rhs.x, y + rhs.y };
}

Point Point::operator-(const Direction& rhs) const
{
    return { x - rhs.x, y - rhs.y };
}


Direction operator-(const Point& lhs, const Point& rhs)
{
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}