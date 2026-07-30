#pragma once

#include <algorithm>
#include <cassert>

template<typename T> 
class Array {
private:
	T* m_data{ nullptr };
	size_t m_size{ 0 };
	size_t m_capacity{ 0 };
public:
	Array() : m_data(new T[8]), m_size(0), m_capacity(8) {}

	Array(size_t size, const T& value) : m_capacity(size), m_size(size) {
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i) m_data[i] = value;
	}

	~Array()
	{
		delete[] m_data;
	}

	Array(const Array& other) : m_data(new T[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity) 
	{
		std::copy(other.m_data, other.m_data + other.m_size, m_data);
	}
	Array(Array&& other) noexcept
	{
		m_data = other.m_data;
		m_capacity = other.m_capacity;
		m_size = other.m_size;

		other.m_data = nullptr;
		other.m_capacity = 0;
		other.m_size = 0;
	}
	Array& operator=(const Array& other) {
		if (this == &other) return *this;
		T* newData = new T[other.m_capacity];
		std::copy(other.m_data, other.m_data + other.m_size, newData);
		delete[] m_data;
		m_data = newData;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		return *this;
	}

	Array& operator=(Array&& other) noexcept
	{
		if (this == &other) return *this;

		delete[] m_data;

		m_data = other.m_data;
		m_capacity = other.m_capacity;
		m_size = other.m_size;

		other.m_data = nullptr;
		other.m_capacity = 0;
		other.m_size = 0;
		return *this;
	}

	void reserve(size_t newCapacity)
	{
		if (newCapacity <= m_capacity) return;
		T* newArray = new T[newCapacity];
		std::copy(m_data, m_data + m_size, newArray);
		delete[] m_data;
		m_data = newArray;
		m_capacity = newCapacity;

	}

	template <typename Self>
	T& operator[](this Self&& self, int i) {
		assert(i < self.m_capacity);
		return self.m_data[i];
	}

	void add(const T& value) {
		if (m_capacity <= m_size) reserve(m_capacity * 2);
		m_data[m_size] = value;
		++m_size;
	}

	bool isEmpty() const {
		return m_size == 0;
	}
	size_t size() const {
		return m_size;
	}
	size_t capacity() const {
		return m_capacity;
	}
	template <typename Self>
	T* data(this Self&& self) {
		return self.m_data;
	}

	class Iterator {
	private:
		T* curPtr;
	public:
		Iterator() : curPtr(nullptr) {}
		explicit Iterator(T* p) : curPtr(p) {}

		T& operator*() const {
			return *curPtr;
		}
		T* operator++() {
			return ++curPtr;
		}
		T* operator--() {
			return --curPtr;
		}
		bool operator==(const Iterator& rhs) {
			return curPtr == rhs.curPtr;
		}
		bool operator!=(const Iterator& rhs) {
			return curPtr != rhs.curPtr;
		}
	};

	Iterator begin() const {
		return Iterator(m_data);
	}
	Iterator end() const {
		return Iterator(m_data + m_size);
	}
};