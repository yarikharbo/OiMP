#include <iostream>

int main(){
	int num = 0;
	std::cout << "Input a natural number: ";
	std::cin >> num;
	if (num < 1) {
		std::cout << "Error\n";
		return 0;
	}
	bool f = 0;
	int temp = num;
	while (temp > 0 && !f) {
		int digit = temp % 10;
		int remain = temp / 10;
		while (remain > 0){
      if (remain % 10 == digit){
        f = true;
        break;
      }
      remain /= 10;
		}
		temp /= 10;
	}
	std::cout << (f ? "Has duplicate digits" : "All digits are unique") << '\n';
	return 0;
}
