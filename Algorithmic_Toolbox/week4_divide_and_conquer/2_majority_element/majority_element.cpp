#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];
    
    //std::cout <<"santhosh1 " <<" ";
    int left_elem = get_majority_element(a, left, (left + right - 1) / 2 + 1);
    //std::cout <<"santhosh2 " <<" ";
    int right_elem = get_majority_element(a, (left + right - 1) / 2 + 1, right);
    //std::cout <<"santhosh3 " <<" ";

    int lcount = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == left_elem) lcount += 1;
    }
    if (lcount > (right - left) / 2) return left_elem;

    int rcount = 0;
    for (int i = left; i < right; i++) {
        if (a[i] == right_elem) rcount += 1;
    }
    if (rcount > (right - left) / 2) return right_elem;

    return -1;
}


/*int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = floor(left + (right-left)/2);
  int majority_present_low_half = majority_element_present(a, left, mid);
  int majority_present_upper_half = majority_element_present(a, mid+1, right);
  return -1;
}*/

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
