#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  
  //int value[W+1][w.size()+1];
  //vector<vector<long> >
  std::vector<std::vector<int>> value;
  value.resize(W+1, std::vector<int>(w.size()+1, 0));
  
  /*for(int i=0; i < w.size()+1; i++)
    for(int j=0; j < W+1; j++)
      value[j][i] = 0;*/

  for(int i=1; i < w.size()+1; i++)
    for(int j=1; j < W+1; j++) {
      value[j][i] = value[j][i-1]; 
      int val=0;
      int wi = w[i-1];
      if(wi <= j) {
        val = value[j-wi][i-1] + wi;
      }
      if(val > value[j][i]) {
        value[j][i] = val;
      }
    }
   
   int final_weight = value[W][w.size()];
   value.clear();
   return final_weight;

  /*int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;*/

}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
