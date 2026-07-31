#pragma once
#include <compare>

class Byte
{
private:
	size_t bytes{ 0ull };
public:
	Byte() {};
	Byte(size_t s) : bytes(s) {}

	size_t getBytes() const {
		return bytes;
	}

	auto operator<=>(const Byte& rhs) const = default;
	bool operator==(const Byte& rhs) const
	{
		return bytes == rhs.bytes;
	}
	size_t b() const 
	{
		return bytes * 8;
	}
	size_t B() const 
	{
		return bytes;
	}
	double Kb() const 
	{
		return b() / 1000;
	}
	double KB() const 
	{
		return bytes / 1000;
	}
	double Mb() const 
	{
		return Kb() / 1000;
	}
	double MB() const 
	{
		return KB() / 1000;
	}
};

Byte operator""_b(size_t i) {
	if (i % 8 != 0) return (i / 8) + 1;
	else return i / 8;
}

Byte operator""_B(size_t i) {
	return i;
}

Byte operator""_Kb(size_t i) {
	return i * 1000 / 8;
}
Byte operator""_KB(size_t i) {
	return i * 1000;
}

Byte operator""_Mb(size_t i) {
	return i * 1000 * 1000 / 8;
}

Byte operator""_MB(size_t i) {
	return i * 1000 * 1000;
}