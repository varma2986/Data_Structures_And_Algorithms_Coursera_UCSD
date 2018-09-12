#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &is_used, vector<int> &order, int dfs_node) {
  //write your code here
  is_used[dfs_node]=1;
  for(size_t i =0;i<adj[dfs_node].size();i++){
    if(!is_used[adj[dfs_node][i]])
    dfs(adj,is_used,order,adj[dfs_node][i]);
  }
  order.push_back(dfs_node);//postorder
}   

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> is_used(adj.size(), 0);
  vector<int> order;
  //write your code here
  for(size_t i =0;i<adj.size();i++){
    if(!is_used[i])
    dfs(adj,is_used,order,i);
  }
  reverse(order.begin(),order.end());//reverse postorder of dfs
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
