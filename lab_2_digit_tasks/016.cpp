#include <iostream>

bool solve(int A, int B) {
    while (A > 0 && B > 0) {
        if (A % 10 == B % 10) {
            A = A / 10;
        }
        B = B / 10;
    }
    return A == 0;
}

int main() {
    int A, B;
    std::cout << "Input two natural numbers A and B: ";
    std::cin >> A >> B;
    if (std::cin.fail() || A <= 0 || B <= 0) {
        std::cout << "Error" << std::endl;
        return 0;
    }
    if (solve(A, B)) {
        std::cout << "Number A can be obtained by deleting digits from number B" << std::endl;
    } else {
        std::cout << "Number A cannot be obtained by deleting digits from number B" << std::endl;
    }
    return 0;
}
