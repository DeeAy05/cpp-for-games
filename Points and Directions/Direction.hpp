#pragma once
#include <cassert>
#include <compare>
struct Direction
{
	float x;
	float y;

	Direction operator+(const Direction& rhs) const;
	Direction operator-(const Direction& rhs) const;
	Direction operator*(float rhs) const;

	template<typename Self>
	float operator[](this Self&& self, size_t i);

	auto operator<=>(const Direction& rhs) const = default;
};
Direction operator*(float lhs, const Direction& rhs);

template<typename Self>
inline float Direction::operator[](this Self&& self, size_t i)
{
	assert(i < 2);
	if (i == 0) return self.x;
	else return self.y;
}

