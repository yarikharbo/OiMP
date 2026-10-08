#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
#include <random>

const int32_t MAX = 100;
const int32_t MOD = 1e+6;

void random_arr(std::vector<double>& arr, int32_t& num, double& left, double& right);
void input_arr(std::vector<double>& arr, int32_t& num);
void validate_array_size(double arrSize);
void validate_menu_choice(int32_t in);
void validate_boundaries(double left, double right);
void sum(std::vector<double>& arr, int32_t num);
void product(int32_t mink, int32_t maxk, std::vector<double>& arr);

void sort_array(std::vector<double>& arr, int32_t num);

int32_t main() {
  try {
    double arrSize;
    std::cout << "Input the array size: ";
    if (!(std::cin >> arrSize)) {
      throw "Error";
    }
    validate_array_size(arrSize);
    int32_t num = round(arrSize);
    std::vector<double> arr(MAX);
    std::cout << "Select the array filling method:\n  0 - Random numbers\n  1 - Input manually\n";
    int32_t inType;
    if (!(std::cin >>inType)) {
      throw "Error";
    }
    validate_menu_choice(inType);
    if (inType == 0) {
      double left{}, right{};
      std::cout << "Input the boundaries (left and right) of the values in the array: ";
      if (!(std::cin >> left >> right)) {
        throw "Error";
      }
      validate_boundaries(left, right);
      if (left > right) std::swap(left, right);
      random_arr(arr, num, left, right);
      std::cout << "Random array: ";
      for (size_t i = 0; i < num; i++) {
        std::cout << arr[i] << ' ';
      }
      std::cout << '\n';
    } else {
      std::cout << "Input n real numbers: ";
      input_arr(arr, num);
    }
    sum(arr, num);
    sort_array(arr, num);
    std::cout << "Sorted array: ";
    for (size_t i = 0; i < num; i++) {
      std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
  } catch (const char* error) {
    std::cout << error << '\n';
    return 0;
  }
  return 0;
}

void random_arr(std::vector<double>& arr, int32_t& num, double& left, double& right) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(left, right);
  for (size_t i = 0; i < num; i++) {
    double value = dist(gen);
    arr[i] = std::round(value * MAX) / MAX;
  }
}

void input_arr(std::vector<double>& arr, int32_t& num) {
  for (size_t i = 0; i < num; i++) {
    if (!(std::cin >> arr[i])) {
      throw "Error";
    }
    if (abs(arr[i]) > MAX) {
      throw "Error";
    }
  }
}

void validate_array_size(double arrSize) {
  int32_t num = round(arrSize);
  if (num < 1 || num > MAX) {
    throw "Error";
  }
}

void validate_menu_choice(int32_t inType) {
  if (inType < 0 || inType > 1) {
    throw "Error";
  }
}

void validate_boundaries(double left, double right) {
  if (abs(left) > 100 || abs(right) > 100) {
    throw "Error";
  }
}

void sum(std::vector<double>& arr, int32_t num) {
  double sum{}, maxk{}, mink{}, maxv = 0, minv = 1.0 * MAX;
  for (size_t i = 0; i < num; i++) {
    if (arr[i] > 0) sum += arr[i];
    if (abs(arr[i]) > maxv) {
      maxk = i;
      maxv = abs(arr[i]);
    }
    if (abs(arr[i]) <= minv) {
      mink = i;
      minv = abs(arr[i]);
    }
  }
  std::cout << "Sum: " << sum;
  product(mink, maxk, arr);
}

void product(int32_t mink, int32_t maxk, std::vector<double>& arr) {
  double prod = 1;
  int32_t div = 0;
  std::cout << "\nProduct: ";
  if (std::min(mink, maxk) + 1 > std::max(mink, maxk) - 1) {
    std::cout << 0 << '\n';
    return;
  }
  for (size_t i = std::min(mink, maxk) + 1; i <= std::max(mink, maxk) - 1; i++) {
    prod = (prod * arr[i]);
    div += (int32_t)prod / MOD;
    while (prod > MOD) {
      prod -= MOD;
    }
  }
  if (div != 0) {
    std::cout << div * 1e+6 << " + " << prod << '\n';
  } else {
    std:: cout << prod << '\n';
  }
}

void sort_array(std::vector<double>& arr, int32_t num) {
  for (size_t i = 0; i < num; i += 2) {
    for (size_t j = i + 2; j < num; j += 2) {
      if (arr[j] > arr[i]){
        double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
