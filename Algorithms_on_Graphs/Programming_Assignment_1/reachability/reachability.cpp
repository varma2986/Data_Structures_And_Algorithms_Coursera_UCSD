#include <iostream>
#include <vector>

using std::vector;
using std::pair;
vector<bool> visited;

int reach(vector<vector<int> > &adj, int x, int y) {
  visited[x] = true;
  if(visited[y] == true) return 1; 
  for(int i=0; i < adj[x].size(); i++) {
    int checkadjvec = adj[x][i];
    if(checkadjvec == y) {
      visited[y] = true;
      return 1;
    }
    if(visited[checkadjvec] == false) {
      reach(adj,checkadjvec,y);
    }
    if(visited[y] == true) return 1; 
  }
  return 0;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  visited.resize(n);
  std::cout << reach(adj, x - 1, y - 1);
}
