#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class Array
{
    private:
        T *array;
        std::size_t _size;
    public:
        Array();
        Array(std::size_t n);
        Array(const Array &other);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](std::size_t index);
        const T &operator[](std::size_t index) const;
        std::size_t size() const;
};

#include "Array.tpp"

#endif
