#include <iostream>
#include <cstddef>
#include "iter.hpp"

void addOne(int &x) {
    x++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "---Before---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    iter(arr, 5, addOne);
    std::cout << std::endl << "---After---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << "---String---" << std::endl;
    const std::string str[] = {"Hello", "World"};
    iter(str, 2, print<std::string>);
    return 0;
}
