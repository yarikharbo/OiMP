// корректный ввод по условию.
#include <iostream>
#include <fstream>
#include <type_traits>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <cstdlib>

void solve(const char*);
int sumOfDigits(int32_t);
int32_t magic(int32_t);
int32_t magic(int32_t, int32_t);
double magic(double, double);
template <typename T> void printResult(const char*, char, T (*operation)(T, T));

int main() {
    solve("integers.txt");
    solve("double.txt");
    return 0;
}

void solve(const char* type) {
    std::ifstream fin(type);
    if (!fin.is_open()) {
        std::cerr << "Cannot open file: " << type << std::endl;
        return;
    }
    char separator = fin.get();
    std::string temp{}, str{};
    while (std::getline(fin, temp)) {
        str += temp;
    }
    char* buf = new char[str.size() + 1];
    std::strcpy(buf, str.c_str());
    if (std::strcmp(type, "integers.txt") == 0) {
        printResult<int32_t>(buf, separator, static_cast<int32_t(*)(int32_t, int32_t)>(magic));
    }
    else {
        printResult<double>(buf, separator, static_cast<double (*)(double, double)>(magic));
    }
    delete[] buf;
    fin.close();
    std::cout << '\n';
}

int sumOfDigits(int32_t num) {
    int32_t sum{};
    num = abs(num);
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int32_t magic(int32_t num) {
    return sumOfDigits(num);
}

int32_t magic(int32_t num1, int32_t num2) {
    return (sumOfDigits(num1) > sumOfDigits(num2) ? num1 : num2);
}

double magic(double num1, double num2) {
    double frac1 = std::abs(num1 - std::floor(num1));
    double frac2 = std::abs(num2 - std::floor(num2));
    return (frac1 > frac2 ? num1 : num2);
}

template <typename T> void printResult(const char* str, char separator, T(*operation)(T, T)) {
    T* arr = new T[std::strlen(str) / 2 + 1];
    const char* start = str;
    const char* end = nullptr;
    size_t arrSize = 0;
    while (*start != '\0') {
        end = std::strchr(start, separator);
        size_t len = 0;
        if (end == nullptr) {
            len = std::strlen(start);
        }
        else {
            len = static_cast<size_t>(end - start);
        }
        if (len > 0) {
            char* token = new char[len + 1];
            std::memcpy(token, start, len);
            token[len] = '\0';
            if constexpr (std::is_same_v<T, double>) {
                arr[arrSize] = static_cast<T>(std::strtod(token, nullptr));
            }
            else {
                arr[arrSize] = static_cast<T>(std::atoi(token));
            }
            ++arrSize;
            delete[] token;
        }
        if (end == nullptr) {
            break;
        }
        start = end + 1;
    }
    for (size_t i = 1; i < arrSize - 1; ++i) {
        if ((operation(arr[i - 1], arr[i]) == arr[i - 1]) && (operation(arr[i], arr[i + 1]) == arr[i + 1])) {
            std::cout << arr[i] << ' ';
        }
    }
    delete[] arr;
}
