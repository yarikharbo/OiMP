#include <iostream>

int main() {
    int N;
    std::cout << "Input natural number N: ";
    std::cin >> N;
    if (std::cin.fail() || N <= 0) {
        std::cout << "Error" << std::endl;
        return 0;
    }
    std::cout << "Pythagorean triples up to " << N << ":" << std::endl;
    bool found = false;
    for (int a = 1; a <= N; a++) {
        for (int b = a; b <= N; b++) {
            for (int c = b; c <= N; c++) {
                if (a * a + b * b == c * c) {
                    std::cout << "(" << a << ", " << b << ", " << c << ")" << std::endl;
                    found = true;
                }
            }
        }
    }
    if (!found) {
        std::cout << "No Pythagorean triples found" << std::endl;
    }
    return 0;
}
