#include <iostream>

void solve(int (&counter)[10], int& n) {
  while (n > 0) {
    int digit = n % 10;
    counter[digit]++;
    n /= 10;
  }
}

int main() {
  int n{};
  std::cout << "Input an integer: ";
  std::cin >> n;
  int counter[10]{};
  solve(counter,n);
  for (int i = 0; i < 10; i++) {
    if (counter[i] != 0) {
      std::cout << "Number of occurrences of the number " << i << " : " << counter[i] << '\n';
    }
  }
  return 0;
}
