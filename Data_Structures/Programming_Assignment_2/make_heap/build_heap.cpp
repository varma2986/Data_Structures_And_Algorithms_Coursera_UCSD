#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void BuildHeap() {
    int size = data_.size();
    for(int i = floor(size/2); i>=0; i--) {
      //cout << "Santhosh calling ShiftDown with i << " << i << "\n";
      ShiftDown(i);
    }
  }


  void ShiftDown(int i) {
    int maxindex = i;
    int size = data_.size();
    int l = 2*i+1;
    //cout << "before processing l is " << l << " maxindex is " << maxindex << "\n";
    if((l < size) && (data_[l] < data_[maxindex])) {
      maxindex = l;
    }
    int r = 2*i+2;
    //cout << "before processing r is " << r << " maxindex is " << maxindex << "\n";
    if((r < size) && (data_[r] < data_[maxindex])) {
      maxindex = r;
    }
    //cout << "after processing r is " << r << " maxindex is " << maxindex <<  " l is " << l << "\n";
    if(i != maxindex) {
        swap(data_[i], data_[maxindex]);
        swaps_.push_back(make_pair(i, maxindex));
        ShiftDown(maxindex);
    }

  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }

 public:
  void Solve() {
    ReadData();
    BuildHeap();
    //GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
