#include <iostream>
#include "Fraction.h"
#include <string>
#include <windows.h>

int main() {
    SetConsoleCP();
    SetConsoleOutputCP();
    try {

        Fraction a(3, 4);
        Fraction b(2, 3);
        Fraction c = IntToFraction(5);

        std::cout << "a = " << a << " (" << a.toDouble() << ")\n";
        std::cout << "b = " << b << " (" << b.toDouble() << ")\n";
        std::cout << "c = " << c << " (" << c.toDouble() << ")\n";
        std::cout << "d = " << d << " (" << d.toDouble() << ")\n\n";

        Fraction sum = a + b;
        Fraction diff = a - b;
        Fraction prod = a * b;
        Fraction quot = a / b

        std::cout << "a + b = " << sum << " (" << sum.toDouble() << ")\n";
        std::cout << "a - b = " << diff << " (" << diff.toDouble() << ")\n";
        std::cout << "a * b = " << prod << " (" << prod.toDouble() << ")\n";
        std::cout << "a / b = " << quot << " (" << quot.toDouble() << ")\n\n";

        Fraction x = a;
        x += b;
        std::cout << "a += b -> " << x << "\n";
        x = a;
        x -= b;
        std::cout << "a -= b -> " << x << "\n";
        x = a;
        x *= b;
        std::cout << "a *= b -> " << x << "\n";
        x = a;
        x /= b;
        std::cout << "a /= b -> " << x << "\n\n";

        Fraction inc = a;
        std::cout << "++inc = " << ++inc << "\n";
        inc = a;
        std::cout << "inc++ = " << inc++ << ", after = " << inc << "\n";
        Fraction dec = a;
        std::cout << "--dec = " << --dec << "\n";
        dec = a;
        std::cout << "dec-- = " << dec-- << ", after = " << dec << "\n\n";

        std::cout << "-a = " << -a << "\n";
        Fraction inv = a;
        std::cout << "!a (inverse) = " << !inv << "\n\n";

        std::cout << std::boolalpha;
        std::cout << "a == b? " << (a == b) << "\n";
        std::cout << "a != b? " << (a != b) << "\n";
        std::cout << "a < b?  " << (a < b) << "\n";
        std::cout << "a > b?  " << (a > b) << "\n\n";

    return 0;
}
