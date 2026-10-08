#include <iostream>

bool isArmstrong(int number) {
    int num = number;
    int sum = 0;
    int digitc = 0;
    int temp = number;
    while (temp > 0) {
        digitc++;
        temp /= 10;
    }
    temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digitc; i++) {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    return sum == num;
}

int main() {
    int n;
    std::cout << "Input a natural number: ";
    std::cin >> n;
    if (std::cin.fail() || n <= 0) {
        std::cout << "Error" << std::endl;
        return 0;
    }
    std::cout << "Armstrong numbers up to " << n << ":" << std::endl;
    int c = 0;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (isArmstrong(i)) {
            if (c > 0) {
                std::cout << " ";
            }
            std::cout << i;
            c++;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No Armstrong numbers found" << std::endl;
    } else {
        std::cout << std::endl;
    }
    return 0;
}
