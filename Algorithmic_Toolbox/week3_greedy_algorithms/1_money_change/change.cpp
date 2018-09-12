#include <iostream>

int get_change(int m) {
  //write your code here
  int num_10 = m/10;
  int bal_10 = m%10;
  int num_5 = bal_10/5;
  int bal_5 = bal_10%5;
  return(num_10+num_5+bal_5);
  
  //return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
