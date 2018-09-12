#include <iostream>
#include <vector>

using std::vector;

int get_change(int m) {
  //write your code here
  vector<int> coins;
  coins.push_back(1);
  coins.push_back(3);
  coins.push_back(4);
  vector<int> MinNumCoins(m+1);
  MinNumCoins[0] = 0;

  for (int i=1; i<=m; i++) {
    MinNumCoins[i] = m;
      for (int j = 0;j<=2;j++) {
        int coin = coins[j];
        int NumCoins;
        if (i >= coin) NumCoins = MinNumCoins[i - coin] + 1;
        if(NumCoins < MinNumCoins[i]) {
          MinNumCoins[i] = NumCoins;
        }
      } 
  }
  return MinNumCoins[m]; 
  //return m / 4;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
