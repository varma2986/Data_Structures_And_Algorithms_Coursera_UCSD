#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = static_cast<int>(values.size());
  std::vector<double> values_per_weights(n);
  for (int i=0; i < n; i++) {
    values_per_weights[i] = (double) values[i]/ (double) weights[i];
    //std::cout << " i is " << i << " values is " << values[i] << " weights is " << weights[i] << " vpw is " << values_per_weights[i] << " \n";
  }

  //Sort based on values_per_weights
  std::vector<std::pair<double,int>>sorted_vpw;

  for (int i = 0 ;i < n ; i++) {
    sorted_vpw.push_back (std::make_pair (values_per_weights[i],i)); // k = value, i = original index
  }

  sort(sorted_vpw.begin(),sorted_vpw.end());

  /*for (int i = 0 ; i < n ; i++){
      std::cout << sorted_vpw[i].first << " " << sorted_vpw[i].second << "\n";
  }*/

  //
  double remaining_capacity = capacity;
  for(int i=n-1; i >=0 && remaining_capacity > 0; i--) {
    int index = sorted_vpw[i].second;
    double min_capacity;
    if(remaining_capacity < weights[index]) {
        min_capacity = remaining_capacity;
    } else {
        min_capacity = weights[index];
    }
    //double min_capacity = std::min(remaining_capacity, weights[index]);
    value = value + (double) sorted_vpw[i].first * (double) min_capacity;
    remaining_capacity = remaining_capacity - min_capacity;
  }


  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
