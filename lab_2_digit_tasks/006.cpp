#include <iostream>

int main() {
    int number;
    std::cout << "Input a natural number: ";
    std::cin >> number;
    if (std::cin.fail() || number <= 0) {
        std::cout << "Error";
        return 0;
    }
    if (number == 1) {
        std::cout << "Prime factors of 1: 1";
        return 0;
    }
    std::cout << "Prime factors of " << number << ": ";
    int temp = number;
    int divisor = 2;
    bool isFirst = true;
    while (temp > 1) {
        if (temp % divisor == 0) {
            if (!isFirst) {
                std::cout << " * ";
            }
            std::cout << divisor;
            temp = temp / divisor;
            isFirst = false;
        } else {
            divisor++;
        }
    }
    return 0;
}
