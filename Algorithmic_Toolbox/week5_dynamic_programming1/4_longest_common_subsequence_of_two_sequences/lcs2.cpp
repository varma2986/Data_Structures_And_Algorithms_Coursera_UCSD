#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int T[a.size()+1][b.size()+1];
  for (int i=0; i < a.size()+1; i++) 
    for (int j = 0; j < b.size()+1; j++)
      T[i][j] = 0;
  
  //for (int i=1; i < a.size()+1; i++) 
  //  for (int j = 1; j < b.size()+1; j++)
  for (int j=1; j < b.size()+1; j++) 
    for (int i = 1; i < a.size()+1; i++)
      {
        if(a[i-1] == b[j-1]) {
          //std::cout << " Increasing i " <<i <<" and j " <<j << " to 1 a is " << a[i] << " b is " << b[j] << "\n";
          T[i][j] = T[i-1][j-1] + 1;
        }
        else
          T[i][j] = std::max(T[i-1][j], T[i][j-1]);
      }
  
  /*std::cout << "All sizes are ";
  for (int i=0; i < a.size()+1; i++) 
    for (int j = 0; j < b.size()+1; j++)
      std::cout << "i is " <<i << " j is " << j << " T is " << T[i][j] << "\n";*/
   
  return T[a.size()][b.size()];
  
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
