#include <bits/stdc++.h>

int main(){
  srand(time(0));
  int n, m;
  std::cout << "Enter the size of the first and second arrays: ";
  std::cin >> n >> m;
  if (n < 1 || m < 1){
    std::cout << "Error\n";
    return 0;
  }
  int nm = n + m;
  int a[n], b[m], c[nm];
  for (int i = 0; i < n; i++){
    a[i] = std::rand();
  }
  for (int i = 0; i < m; i++){
    b[i]=std::rand();
  }
  /*for (int i = 0; i < n; i++){
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++){
    std::cin >> b[i];
  }
  */
  std::sort(a,a+n);
  std::sort(b,b+m);
  int i, j;
  i = j = 0;
  while (i < n || j < m){
    if (i < n && a[i] <= b[j]){
      c[i + j] = a[i];
      i++;
    }
    else if (j < m){
      c[i + j] = b[j];
      j++;
    }
  }
  for (int i = 0; i < nm; i++) std::cout << c[i] << ' ';
  std::cout << '\n';
}
