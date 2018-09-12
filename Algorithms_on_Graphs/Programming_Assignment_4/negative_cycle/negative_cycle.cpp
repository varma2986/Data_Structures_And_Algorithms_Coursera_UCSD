#include <iostream>
#include <vector>

using std::vector;

//Logic: Do Bellmans-Ford Algo for adj.size()-1 cycles
//Then , do Relax Edges for one more cycle and see if any node can be relaxed
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  const int INF_NUM = 100000000;
  vector<int> dis(adj.size(),INF_NUM);
  dis[0]=0;
  //Bellman's-Fod algo for n-1 cycles
  for(size_t k =1;k<adj.size();k++){
    for(size_t i =0;i<adj.size();i++){
      for(size_t j =0;j<adj[i].size();j++){
        int next = adj[i][j];
        if(dis[i]+cost[i][j]<dis[next])
          dis[next]=dis[i]+cost[i][j];
      }
    }
  }
  
  //Relax edge for one more cycle
  for(size_t i =0;i<adj.size();i++){
    for(size_t j =0;j<adj[i].size();j++){
      int next = adj[i][j];
      if(dis[i]+cost[i][j]<dis[next]) return 1;
    }
  }

  return 0;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
