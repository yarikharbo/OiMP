#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>
#include <vector>
#include <type_traits>

void solve();
void check_ifile(std::ifstream& fin);
void check_ofile(std::ofstream& fout);
void check_integer(int32_t& a, int32_t& b, std::istream& in = std::cin);
template <typename T> std::vector<std::vector<T>> input_matrix(size_t rows, size_t columns, std::istream& in = std::cin);
template <typename T> void process_matrix(size_t rows, size_t columns, std::istream& in = std::cin, std::ostream& out = std::cout);
template <typename T> void sort_matrix(std::vector<std::vector<T>>& matrix, size_t rows, int32_t sortType);
template <typename T> void output_matrix(std::vector<std::vector<T>>& matrix, size_t rows, size_t columns, std::ostream& out = std::cout);
template <typename T> std::vector<std::vector<T>> random_matrix(size_t rows, size_t cols);
int32_t sort_type(std::istream& in = std::cin, std::ostream& out = std::cout);
template <typename T> void process_random_matrix(size_t rows, size_t columns);

int main() {
    try {
        solve();
    }
    catch (const char* err) {
        std::cerr << err << std::endl;
    }
    return 0;
}

void solve() {
    std::cout << "Select input method:\n";
    std::cout << "  1 - input and writing to a text file\n";
    std::cout << "  2 - generating random numbers and writing them to a text file\n";
    std::cout << "  3 - input from a text file, and output to the console\n";
    int32_t inputType{};
    std::cin >> inputType;
    if (inputType == 1) {
        std::ifstream fin("input.txt");
        std::ofstream fout("output.txt");
        check_ifile(fin);
        check_ofile(fout);
        int32_t rows{}, columns{};
        check_integer(rows, columns, fin);
        int32_t matrixType{};
        fin >> matrixType;
        if (matrixType == 1) {
            process_matrix<int>(rows, columns, fin, fout);
        }
        else if (matrixType == 2) {
            process_matrix<double>(rows, columns, fin, fout);
        }
        else if (matrixType == 3) {
            process_matrix<std::string>(rows, columns, fin, fout);
        }
        else {
            throw "Error. Wrong matrix type.";
        }
        std::cout << "Processed.\n";
        fin.close();
        fout.close();
    }
    else if (inputType == 2) {
        std::cout << "Enter the matrix dimensions:\n";
        int32_t rows{}, columns{};
        check_integer(rows, columns);
        std::cout << "Select the type of elements in the matrix:\n";
        std::cout << "  1 - int\n";
        std::cout << "  2 - double\n";
        std::cout << "  3 - string\n";
        int32_t matrixType{};
        std::cin >> matrixType;
        if (matrixType == 1) {
            process_random_matrix<int>(rows, columns);
        }
        else if (matrixType == 2) {
            process_random_matrix<double>(rows, columns);
        }
        else if (matrixType == 3) {
            process_random_matrix<std::string>(rows, columns);
        }
        else {
            throw "Error. Wrong matrix type.";
        }
    }
    else if (inputType == 3) {
        std::ifstream fin("input.txt");
        check_ifile(fin);
        int32_t rows{}, columns{};
        check_integer(rows, columns, fin);
        int32_t matrixType{};
        fin >> matrixType;
        if (matrixType == 1) {
            process_matrix<int>(rows, columns, fin);
        }
        else if (matrixType == 2) {
            process_matrix<double>(rows, columns, fin);
        }
        else if (matrixType == 3) {
            process_matrix<std::string>(rows, columns, fin);
        }
        else {
            throw "Error. Wrong matrix type.";
        }
        fin.close();
    }
    else {
        throw "Error. Wrong input type.";
    }
}

void check_ifile(std::ifstream& fin) {
    if (!fin.good()) {
        throw "Error. File doesn't exist.";
    }
    if (fin.peek() == EOF) {
        throw "Error. File is empty.";
    }
}

void check_ofile(std::ofstream& fout) {
    if (!fout) {
        throw "Error. Failed to create output file.";
    }
}

void check_integer(int32_t& a, int32_t& b, std::istream& in) {
    if (!(in >> a >> b) || a <= 0 || b <= 0) {
        throw "Error. Wrong matrix size.";
    }
}

template <typename T> std::vector<std::vector<T>> input_matrix(size_t rows, size_t columns, std::istream& in) {
    std::vector<std::vector<T>> matrix(rows, std::vector<T>(columns));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            in >> matrix[i][j];
        }
    }
    return matrix;
}

template <typename T> void process_matrix(size_t rows, size_t columns, std::istream& in, std::ostream& out) {
    auto matrix = input_matrix<T>(rows, columns, in);
    int32_t sortType{};
    in >> sortType;
    if (sortType == 1 || sortType == 2) {
        sort_matrix<T>(matrix, rows, sortType);
    }
    else {
        throw "Error. Wrong type.";
    }
    out << "Sorted matrix:\n";
    output_matrix<T>(matrix, rows, columns, out);
}

template <typename T> void sort_matrix(std::vector<std::vector<T>>& matrix, size_t rows, int32_t sortType) {
    for (size_t i = 0; i < rows; ++i) {
        if (sortType == 1) {
            std::sort(matrix[i].begin(), matrix[i].end());
        }
        else {
            std::sort(matrix[i].begin(), matrix[i].end(), std::greater<T>());
        }
    }
}

template <typename T> void output_matrix(std::vector<std::vector<T>>& matrix, size_t rows, size_t columns, std::ostream& out) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            out << matrix[i][j] << std::setw(5);
        }
        out << '\n';
    }
}

template <typename T> std::vector<std::vector<T>> random_matrix(size_t rows, size_t cols) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::vector<std::vector<T>> matrix(rows, std::vector<T>(cols));
    if constexpr (std::is_same<T, int>::value) {
        std::cout << "Enter limits (from -100 to 100):";
        int left{}, right{};
        if (!(std::cin >> left >> right)) {
            throw "Error. Invalid bounds.";
        }
        if (left < -100 || right > 100) {
            throw "Error. Wrong bounds.";
        }
        if (left > right) {
            std::swap(left, right);
        }
        std::uniform_int_distribution<int> dist(left, right);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                matrix[i][j] = dist(gen);
            }
        }
    }
    else if constexpr (std::is_same<T, double>::value) {
        std::cout << "Enter limits (from -100 to 100):";
        double left{}, right{};
        if (!(std::cin >> left >> right)) {
            throw "Error. Invalid bounds.";
        }
        if (left < -100.0 || right > 100.0) {
            throw "Error. Wrong bounds.";
        }
        if (left > right) {
            std::swap(left, right);
        }
        std::uniform_real_distribution<double> dist(left, right);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                matrix[i][j] = dist(gen);
            }
        }
    }
    else if constexpr (std::is_same<T, std::string>::value) {
        std::cout << "Enter desired string length (1 to 10):\n";
        int len{};
        if (!(std::cin >> len)) {
             throw "Error. Invalid length.";
        }
        if (len < 1 || len > 10) {
            throw "Error. Length out of range.";
        }
        std::uniform_int_distribution<int> charDist(0, 25);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::string s;
                s.reserve(len);
                for (int k = 0; k < len; ++k) {
                    char c = static_cast<char>('a' + charDist(gen));
                    s.push_back(c);
                }
                matrix[i][j] = s;
            }
        }
    }
    return matrix;
}

int32_t sort_type(std::istream& in, std::ostream& out) {
    int32_t sortType{};
    out << "How do you want to sort the matrix:\n";
    out << "  1 - sort in ascending order\n";
    out << "  2 - sort in descending order\n";
    if (!(in >> sortType)) {
        throw "Error. Invalid sort type.";
    }
    if (sortType != 1 && sortType != 2) {
        throw "Error. Wrong type.";
    }
    return sortType;
}

template <typename T> void process_random_matrix(size_t rows, size_t columns) {
    auto matrix = random_matrix<T>(rows, columns);
    std::cout << "Random matrix:\n";
    output_matrix<T>(matrix, rows, columns);
    int32_t sortType = sort_type();
    if (sortType == 1 || sortType == 2) {
        sort_matrix<T>(matrix, rows, sortType);
    }
    else {
        throw "Error. Wrong type.";
    }
    std::cout << "Sorted matrix:\n";
    output_matrix<T>(matrix, rows, columns);
}
