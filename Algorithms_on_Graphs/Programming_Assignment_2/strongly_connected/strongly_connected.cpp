#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void depth_first_search(int start,vector<vector<int> > &adj_sc_temp,vector<bool> &visited,vector<int> &order){
  visited[start]=true;
  for(size_t i=0;i<adj_sc_temp[start].size();i++){
    if(!visited[adj_sc_temp[start][i]])
    depth_first_search(adj_sc_temp[start][i],adj_sc_temp,visited,order);
  }
  order.push_back(start);
}

void explore_graph(int start,vector<vector<int> > &adj_sc_temp,vector<bool> &visited){
  visited[start]=true;
  for(size_t i=0;i<adj_sc_temp[start].size();i++){
    if(!visited[adj_sc_temp[start][i]])
    explore_graph(adj_sc_temp[start][i],adj_sc_temp,visited);
  }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  vector<vector<int> > adj_sc_temp(adj.size());
  for(size_t i =0;i<adj.size();i++){
    for(size_t j=0;j<adj[i].size();j++){
      adj_sc_temp[adj[i][j]].push_back(i);
    }
  }
  vector<bool> visited(adj.size());
  vector<int> order;
  for(size_t i=0;i<adj_sc_temp.size();i++){
    if(!visited[i])
    depth_first_search(i,adj_sc_temp,visited,order);
  }
  reverse(order.begin(),order.end());
  fill(visited.begin(),visited.end(),0);
  for(size_t i =0;i<order.size();i++){
    if(!visited[order[i]]){
    explore_graph(order[i],adj,visited);
    result++;
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
