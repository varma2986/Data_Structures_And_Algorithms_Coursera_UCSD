#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

std::vector<int> distance;

void do_bfs(vector<vector<int> > &adj, int s) {
  //std::cout<<"Doing BFS for node " << s << "\n";
  distance[s] = 0;
  queue<int> adj_queue;
  adj_queue.push(s);
  while(!adj_queue.empty()) {
    int u = adj_queue.front();
    adj_queue.pop();
    vector<int> adj_nodes_u = adj[u];
    for(int i = 0; i< adj_nodes_u.size(); i++) {
      int node = adj_nodes_u[i];
     // std::cout<<"child Node " << node << "\n";
      if(distance[node] == -1) {
          adj_queue.push(node);
          distance[node] = distance[u] + 1;
          //std::cout<<"Setting distance for node " << node << " to " << distance[node] << "\n";
      }
    }
  }
  return;
}


int distance_nodes(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  for(int i = 0; i< adj.size();i++) {
    distance[i] = -1;
  }
  do_bfs(adj,s);
  return distance[t];
}
/*int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  return -1;
}*/

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  distance.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance_nodes(adj, s, t);
}
