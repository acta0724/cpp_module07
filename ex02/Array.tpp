#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <new>

template <typename T>
Array<T>::Array() : array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(std::size_t n) : array(new T[n]), _size(n) {}


template <typename T>
Array<T>::Array(const Array &other) : array(nullptr), _size(other._size) {
	if (_size > 0) {
		array = new T[_size];
		for (std::size_t i = 0; i < other._size; i++)
			array[i] = other.array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete [] array;
		array = new T[other._size];
		_size = other._size;
		if (_size > 0) {
			for (std::size_t i = 0; i < other._size; i++)
				array[i] = other.array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete [] array;
}

template <typename T>
T& Array<T>::operator[](std::size_t index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return array[index];
}

template <typename T>
std::size_t Array<T>::size() const {
	return _size;
}

#endif
