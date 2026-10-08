#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>

void check_ifile(std::ifstream& fin);
void solve(std::ifstream& fin);
void check_size(std::ifstream& fin, int32_t& arrSize);
std::vector<std::string> input_arr(std::ifstream& fin, int32_t& arrSize, char sep);
template <typename T> T magic(T a, T b);
template <typename T> void printResult(void (*magic)(T), int32_t* arr, int32_t arrSize);

int main() {
  try {
    std::ifstream fin("integers.txt");
    check_ifile(fin);
    solve();
    fin.close();

    std::cout << '\n';

    std::ifstream fin("double.txt");
    check_ifile(fin);
    solve(fin);
    fin.close();
  }
  catch (const char* err) {
    std::cerr << err << '\n';
  }
  return 0;
}

void solve(std::ifstream& fin) {
  check_ifile(fin);
  char sep;
  fin.get(sep);
  int32_t arrSize{};
  check_size(fin, arrSize);
  fin.ignore();
  std::vector<std::string> arr = input_arr(fin, arrSize, sep);
  printResult(&magic(a, b), arr, arrSize);
}

void check_ifile(std::ifstream& fin) {
  if (!fin.good()) {
    throw "File doesn't exist";
  }
  if (fin.peek() == EOF) {
    throw "File is empty";
  }
}

void check_size(std::ifstream& fin, int32_t& a) {
  if (!(fin >> a)) {
    if (arrSize <= 0) {
      throw "Error. Wrong size";
    }
  }
}

std::vector<std::string> input_arr(std::ifstream& fin, int32_t& arrSize, char sep) {
  std::string data;
  std::string line;
  while (std::getline(fin, line)) {
    data += line;
  }
  size_t i{};
  while (i != data.size()) {
    if ()
  }
  return result;
}

template <typename T> T magic(T a, T b) {

}

template <typename T> void printResult(void (*process)(T), int32_t* arr, int32_t arrSize) {
  for (size_t i = 1; i < arrSize - 1; ++i) {
    if (process(arr[i - 1], arr[i]) > arr[i]) && process(arr[i + 1], arr[i]) > arr[i]) {
      std::cout << arr[i] << ' ';
    }
  }
}
