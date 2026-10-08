#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <iomanip>

const int32_t MAX = 100;

void solve();
void is_number(int32_t& num);
void validate_array_size(int32_t size);
void validate_menu_choice(int32_t in);
void validate_boundaries(int32_t& left, int32_t& right);
void create_arr(int32_t** &arr, int32_t size);
void random1_arr(int32_t** &arr, int32_t size, int32_t left, int32_t right);
void random2_arr(int32_t** &arr, int32_t size, int32_t left, int32_t right);
void output_arr(int32_t** arr, int32_t size);
void input_arr(int32_t** arr, int32_t size);
int32_t triangle_max(int32_t** arr, int32_t size);
void find_max(int32_t** arr, int32_t size, int32_t& mx, int32_t& x, int32_t& y);
void rearrange(int32_t** arr, int32_t size);

int32_t main(){
  srand(time(0));
  try {
    solve();
  }
  catch (const char* err) {
    std::cout << err << '\n';
  }
  return 0;
}

void solve(){
  int32_t size{};
  std::cout << "Enter the size of the square matrix: ";
  is_number(size);
  validate_array_size(size);
  int32_t in{};
  std::cout << "How do you want to enter the array:\n  0 - Manually\n  1 - Randomly\n  2 - Randomly using the Mersenne vortex\n";
  is_number(in);
  validate_menu_choice(in);
  int32_t** arr = new int32_t*[size];
  create_arr(arr, size);
  if (in == 1) {
    int32_t left, right;
    std::cout << "Enter the left and right boundaries for number generation: ";
    is_number(left);
    is_number(right);
    validate_boundaries(left, right);
    random1_arr(arr, size, left, right);
    std::cout << "Random matrix:\n";
    output_arr(arr, size);
  } else if (in == 0){
    std::cout << "Enter the matrix: \n";
    input_arr(arr, size);
  } else {
    int32_t left, right;
    std::cout << "Enter the left and right boundaries for number generation: ";
    is_number(left);
    is_number(right);
    validate_boundaries(left, right);
    random2_arr(arr, size, left, right);
    std::cout << "Random matrix:\n";
    output_arr(arr, size);
  }
  std::cout << "The maximum element in the lower right triangle of the matrix: " << triangle_max(arr, size) << '\n';
  rearrange(arr, size);
  std::cout << "Rearranged matrix:\n";
  output_arr(arr, size);
  delete[] arr;
}

void is_number(int32_t& num) {
  if (!(std::cin >> num)) {
    throw "Error. Enter a natural number!";
  }
}

void validate_array_size(int32_t size) {
  if (size < 1 || size > MAX) {
    throw "Error. Incorrect size!";
  }
}

void validate_menu_choice(int32_t in) {
  if (in != 1 && in != 0 && in != 2) {
    throw "Error. Incorrect option!";
  }
}

void validate_boundaries(int32_t& left, int32_t& right) {
  if (left > right) {
    std::swap(left, right);
  }
}

void create_arr(int32_t**& arr, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        arr[i] = new int32_t[size];
    }
}

void random1_arr(int32_t** &arr, int32_t size, int32_t left, int32_t right) {
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j < size; ++j) {
      arr[i][j] = left + rand() % (right - left + 1);
    }
  }
}

void random2_arr(int32_t** &arr, int32_t size, int32_t left, int32_t right) {
  std::mt19937 gen;
  std::uniform_int_distribution<int> distr(left, right);
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j < size; ++j) {
      arr[i][j] = distr(gen);
    }
  }
}

void output_arr(int32_t** arr, int32_t size) {
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j < size; ++j){
      std::cout << std::setw(5) << arr[i][j];
    }
    std::cout << '\n';
  }
}

void input_arr(int32_t** arr, int32_t size) {
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j <size; ++j) {
      if (!(std::cin >> arr[i][j])) {
        throw "Error. Enter a number!";
      }
    }
  }
}

int32_t triangle_max(int32_t** arr, int32_t size) {
  int32_t mx = INT_MIN;
  for (int32_t i = 1; i < size; ++i) {
    for (int32_t j = size - i; j < size; ++j) {
      if (mx < arr[i][j]) {
        mx = arr[i][j];
      }
    }
  }
  return mx;
}

void find_max(int32_t** arr, int32_t size, int32_t& mx, int32_t& x, int32_t& y) {//
  for (int32_t i = 0; i < size; ++i) {
    for (int32_t j = 0; j < size; ++j) {
      if (mx < arr[i][j]) {
        mx = arr[i][j];
        x = i;
        y = j;
      }
    }
  }
}

void rearrange(int32_t** arr, int32_t size) {
  int32_t mx = INT_MIN, x{}, y{};
  find_max(arr, size, mx, x, y);
  std::cout << "The maximum element of matrix: " << mx << '\n';
  for (int32_t i = 0; i < size; ++i) {
    int32_t t = arr[i][0];
    arr[i][0] = arr[i][y];
    arr[i][y] = t;
  }
  for (int32_t i = 0; i < size; ++i) {
    int32_t t = arr[0][i];
    arr[0][i] = arr[x][i];
    arr[x][i] = t;
  }
}

