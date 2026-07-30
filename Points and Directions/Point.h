#pragma once
#include "Direction.hpp">
#include <compare>
#include <cassert>
struct Point {
	float x;
	float y;

	Point operator+(const Direction& rhs) const;
	Point operator-(const Direction& rhs) const;

	template<typename Self>
	float operator[](this Self&& self, size_t i);

	auto operator<=>(const Point& rhs) const = default;
};

Direction operator-(const Point& lhs, const Point& rhs);

template<typename Self>
inline float Point::operator[](this Self&& self, size_t i)
{
	assert(i < 2);
	if (i == 0) return self.x;
	else return self.y;
}

