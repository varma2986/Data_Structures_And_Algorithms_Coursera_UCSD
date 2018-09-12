#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;
void explore(vector<vector<int> > &adj, int expl_node) {
   visited[expl_node] = true;
   for(int i=0; i < adj[expl_node].size(); i++) {
     int sub_node = adj[expl_node][i];
     if(visited[sub_node] == false)  {
       explore(adj, sub_node);
     }
   }
}

int explore_graph(vector<vector<int> > &adj) {
    int num_cc = 0;
    visited.resize(adj.size());
    for(int i = 0 ; i < adj.size(); i++) {
        if(visited[i] == false) {
          num_cc = num_cc + 1;
          explore(adj,i);
        }
    }
    return num_cc;
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  res = explore_graph(adj);
  return res;
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
  //std::cout << number_of_components(adj);
  std::cout << explore_graph(adj);
}
