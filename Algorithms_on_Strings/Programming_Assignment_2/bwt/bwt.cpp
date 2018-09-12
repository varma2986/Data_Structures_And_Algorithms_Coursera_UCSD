#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string &text) {
  string result = "";

  // write your code here
  // Implememting the BWT as per the algorithm mentioned in the lecture
  vector<string> BWT_Matrix;
  BWT_Matrix.push_back(text);
  for (size_t i = 1; i < text.size(); i++) {
    string BWTMatrixEntry;
    BWTMatrixEntry.resize(text.size()); 
    std::rotate_copy(text.begin(), text.begin() + i, text.end(),
                     BWTMatrixEntry.begin()); 
    BWT_Matrix.push_back(BWTMatrixEntry);
  }
  //Sort the matrix ascending order
  std::sort(BWT_Matrix.begin(), BWT_Matrix.end());
  for (size_t i = 0; i < BWT_Matrix.size(); i++)
    result += BWT_Matrix[i][text.size() - 1];
  return result;
}

/*string BWT(const string& text) {
  string result = "";

  // write your code here

  return result;
}*/

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
