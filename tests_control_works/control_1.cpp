#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <windows.h>

void solve();
void validate_string(std::string& str);
int32_t find_matrix_size(std::string& str);
void matrix_filling(std::vector<std::vector<char>> &chr, std::string& str, size_t msize);
std::string string_of_columns(std::vector<std::vector<char>> &chr, size_t msize);
void matrix_output(std::vector<std::vector<char>> &chr, size_t msize);

int32_t main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  try {
    solve();
  }
  catch (const char* err) {
    std::cout << err << std::endl;
  }
  return 0;
}

void solve() {
  std::cout << "Enter a string:" << std::endl;
  std::string str;
  getline(std::cin, str);
  validate_string(str);
  size_t msize = find_matrix_size(str);
  std::vector<std::vector<char>> chr(msize, std::vector<char>(msize));
  matrix_filling(chr, str, msize);
  std::cout << "Matrix made from the string:" << std::endl;
  matrix_output(chr, msize);
  std::string str2 = string_of_columns(chr, msize);
  std::cout << "String made of matrix columns:" << std::endl;
  std::cout << str2 << std::endl;
}

void validate_string(std::string& str) {
  if (str == "") {
    throw "Error. String is empty!";
  }
  if (str.size() > 100) {
    throw "Error. The string size must be less then 100!";
  }
}

int32_t find_matrix_size(std::string& str) {
  size_t msize = ceil(sqrt(str.size()));
  return msize;
}

void matrix_filling(std::vector<std::vector<char>> &chr, std::string& str, size_t msize) {
  for (size_t i = 0; i < msize; ++i) {
    for (size_t j = 0; j < msize; ++j) {
      if (i * msize + j < str.size()) {
        chr[i][j] = str[i * msize + j];
      } else {
        chr[i][j] = '*';
      }
    }
  }
}

std::string string_of_columns(std::vector<std::vector<char>> &chr, size_t msize) {
  std::string str2;
  for (size_t i = 0; i < msize; ++i) {
    for (size_t j = 0; j < msize; ++j) {
      str2 += chr[j][i];
    }
  }
  return str2;
}

void matrix_output(std::vector<std::vector<char>> &chr, size_t msize) {
  for (size_t i = 0; i < msize; ++i) {
    for (size_t j = 0; j < msize; ++j) {
      std::cout << chr[i][j];
    }
    std::cout << std::endl;
  }
}
