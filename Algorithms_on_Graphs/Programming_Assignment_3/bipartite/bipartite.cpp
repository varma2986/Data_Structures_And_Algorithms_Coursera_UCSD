#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

vector<int> partition;

int is_bipartite(vector<vector<int> > &adj) {
  //partition[0] = 0;
  queue<int> adj_queue;
  //adj_queue(0);
  for(int i=0; i < adj.size();i++) {
    if(partition[i] == 2) adj_queue.push(i);
    while(!adj_queue.empty()) {
      int u = adj_queue.front();
      adj_queue.pop();
      vector<int> adj_nodes_u = adj[u];

      //Colour Assignment to this node
      //Case1: This node u has no colour , and none of its adjacent nodes have colour
      //Case2: This node has no colour , but one of its adjacent nodes have colour
      if(partition[u] == 2) {
        int speculative_partition = 0;
        for(int j=0; j < adj_nodes_u.size(); j++) {
          if(adj_nodes_u[j] == u) continue;
          if(partition[adj_nodes_u[j]] !=2) {
            speculative_partition = (partition[adj_nodes_u[j]] == 1) ? 0 : 1;
            break;
          }
        }
        partition[u] = speculative_partition;
      }
      //Case3: This node has colour

      //Check for bipartite
      for(int j = 0; j < adj_nodes_u.size(); j++) {
        if(adj_nodes_u[j] == u) continue;
        if(partition[adj_nodes_u[j]] == 2) {
          partition[adj_nodes_u[j]] = (partition[u] == 0) ? 1 : 0;
          adj_queue.push(adj_nodes_u[j]);
        }
        if(partition[adj_nodes_u[j]] == partition[u]) return 0;
      }
    }
  }


  return 1;

}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  for(int i=0; i< adj.size();i++) {
      partition[i] = 2;
  }
  return is_bipartite(adj);
  //return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  partition.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
