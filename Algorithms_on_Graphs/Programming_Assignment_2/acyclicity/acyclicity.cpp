#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

int is_cyclic_node(vector<vector<int> > &adj, int sub_node, int expl_node) {
  vector<int> this_node_neighbours;
  vector<int>::iterator it;

  this_node_neighbours.resize(adj[sub_node].size());
  this_node_neighbours = adj[sub_node];
  it = std::find(this_node_neighbours.begin(), this_node_neighbours.end(),expl_node);
  if(it != this_node_neighbours.end())  {
    //std::cout << "returning one here \n";
    return 1;
  }
  for(int i=0;i<this_node_neighbours.size(); i++) {
      return is_cyclic_node(adj, this_node_neighbours[i], expl_node);
  }
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  for(int i = 0; i < adj.size(); i++) {
    //std::cout << "checking cyclicity node " << i << " \n";
    if(is_cyclic_node(adj,i,i) == 1) return 1;
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
  }
  std::cout << acyclic(adj);
}
