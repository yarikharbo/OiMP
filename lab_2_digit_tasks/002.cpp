#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout << "Input a natural number: ";
  std::cin >> s;
  if (s.empty()) {
    std::cout << "Error\n";
    return 0;
  }
  for (char c : s) {
    if (!isdigit(c)) {
      std::cout << "Error\n";
      return 0;
    }
  }
  int d = 9;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] - '0' < d) {
      d = s[i] - '0';
    }
  }
  if (d == 0) {
    std::cout << "Result: " << s << '\n';
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if ((s[i] - '0') % d == 0) {
      s.erase(i, 1);
      i--;
    }
  }
  std::cout << "Result: " << s << '\n';
  return 0;
}
