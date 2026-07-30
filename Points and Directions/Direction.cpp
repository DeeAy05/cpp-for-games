#include "Direction.hpp"

Direction Direction::operator+(const Direction& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}

Direction Direction::operator-(const Direction& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

Direction Direction::operator*(float rhs) const
{
	return { x * rhs, y * rhs };
}

Direction operator*(float lhs, const Direction& rhs)
{
	return { lhs * rhs.x, lhs * rhs.y };
}