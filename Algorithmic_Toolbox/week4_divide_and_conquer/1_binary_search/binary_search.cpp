#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;

long int binary_search_rec(const vector<int> &a, long int low, long int high, int x) {
  if(high < low) {
      return -1;
  }
  long int mid = floor(low + (high-low)/2);
  if(x == a[mid]) return mid;
  else if (x < a[mid]) return binary_search_rec(a, low, mid-1, x);
  else return binary_search_rec(a, mid+1, high, x);
}

/*long int binary_search(const vector<int> &a, int x) {
  long int left = 0, right = (long int)a.size(); 
  long int mid;
  if (right < left) {
      return left-1;
  }
  mid = floor(left + (right-left)/2);
  if(x == a[mid]) return mid;
  else if (x < a[mid])
      return binary_search(a, left, mid-1, x)
  else
      return binary_search(a, mid+1, right, x)
  //write your code here
  while (left <= right) {
    mid = floor(left + (right-left)/2);
    //mid = left + (right-left)/2;
    if(x == a[mid]) return mid;
    else if(x < a[mid]) right = mid-1;
    else left = mid+1;
  }
  return -1;

}*/


int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long int n;
  std::cin >> n;
  vector<int> a(n);
  //vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long int m;
  std::cin >> m;
  vector<int> b(m);
  for (long int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    //std::cout << binary_search(a, b[i]) << ' ';
    std::cout << binary_search_rec(a, 0, n-1, b[i]) << ' ';
  }
}
