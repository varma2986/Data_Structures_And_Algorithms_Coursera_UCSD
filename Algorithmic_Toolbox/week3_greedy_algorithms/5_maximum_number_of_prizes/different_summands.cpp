#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int remaining_elements = n;
  int current = 1;
  int next;
  int next_remaining;
  while(remaining_elements > 0) {
      next = current+1;
      next_remaining = remaining_elements - current;
      if(next_remaining < next) {
          summands.push_back(remaining_elements);
          remaining_elements = 0;
      } else {
          summands.push_back(current);
          remaining_elements = remaining_elements - current;
          current = next;
      }
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
