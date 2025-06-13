#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <exception>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(std::size_t n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
	for (std::size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete [] _array;
		_array = new T[other._size];
		_size = other._size;
		for (std::size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
T& Array<T>::operator[](std::size_t index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](std::size_t index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _array[index];
}

template <typename T>
std::size_t Array<T>::size() const {
	return _size;
}

#endif
