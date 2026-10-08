#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

int main(){
  int x{}, k{};
  std:: cout << "Enter x > 0 and k > 0 : ";
  std::cin >> x >> k;
  if (k < 1 || x < 1){
    std::cout << "Error\n";
    return 0;
  }
  double epsilon = 1;
  for (int i = 0; i < k; i++){
    epsilon /= 10;
  }
  double sum = M_PI / 2;
  int n = 1;
  int sign = -1;
  double term = x;
  while (1.0 / ((2 * n - 1) * term) >= epsilon){
    sum += sign * 1.0 / ((2 * n - 1) * term);
    n++;
    sign *= -1;
    term *= x * x;
  }
  double arctg = atan(x);
  std::cout << arctg << ' ' << sum << '\n';
  return 0;
}
/*
1 5

1 10
*/
