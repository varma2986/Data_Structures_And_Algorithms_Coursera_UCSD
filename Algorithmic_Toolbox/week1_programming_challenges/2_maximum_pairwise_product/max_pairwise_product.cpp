#include <iostream>
#include <vector>
#include <cstdint>

using std::vector;
using std::cin;
using std::cout;
using std::max;

// Optimized and faster
int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) {
  int big1pos = 0;
  int big2pos = 0;
  int n = numbers.size();
  for(int i=1; i < n; ++i) {
    if(numbers[i] > numbers[big1pos]) {
      big1pos = i;
    }
  }
  big2pos = (big1pos == 0) ? 1 : 0;
  for(int i=0; i < n; i++) {
    if(i != big1pos) {
      if(numbers[i] > numbers[big2pos]) {
        big2pos = i;
      }
    }
  }
return (numbers[big1pos] * numbers[big2pos]);
}

/*Naive
int MaxPairwiseProduct(const vector<int>& numbers) {
int product = 0;
int n = numbers.size();
for (int i = 0; i < n; ++i) {
for (int j = i + 1; j < n; ++j) {
product = max(product, numbers[i] * numbers[j]);
}
}
return product;
}*/


int main() {
int n;
cin >> n;
vector<int64_t> numbers(n);
for (int i = 0; i < n; ++i) {
cin >> numbers[i];
}
int64_t product = MaxPairwiseProduct(numbers);
cout << product << "\n";
return 0;
}
