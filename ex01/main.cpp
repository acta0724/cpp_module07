#include <iostream>
#include <cstddef>
#include "iter.hpp"
#include <string>

void addOne(int &x) {
    ++x;
}

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "---Before---" << std::endl;
    for (std::size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    ::iter(arr, sizeof(arr) / sizeof(arr[0]), addOne);
    std::cout << std::endl << "---After---" << std::endl;
    for (std::size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl << std::endl << "---String---" << std::endl;
    const std::string str[] = {"Hello", "World"};
    ::iter(str, sizeof(str) / sizeof(str[0]), print<std::string>);
    return 0;
}
