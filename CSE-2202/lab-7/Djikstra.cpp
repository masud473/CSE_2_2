#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int dist = 0, node = 0;
  Node() {}
  Node(int a, int b) : dist(b), node(a) {}
  bool operator<(const Node &other) const { return this->dist > other.dist; }
};
int main() {
  int V = 5;
  vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5},
                               {2, 3, 2}, {2, 4, 1}, {3, 4, 3}};

  vector<vector<vector<int>>> adj(V);
  for (auto &edge : edges) {
    adj[edge[0]].push_back({edge[1], edge[2]});
  }

  priority_queue<Node> p;
  p.push(Node(0, 0));
  vector<int> distances(adj.size(), 1e9 + 7);
  vector<bool> visited(adj.size()); 
  distances[0] = 0;
  while (p.size()) {
    Node temp = p.top();
    p.pop();
    visited[temp.node] = true;
    for (auto &i : adj[temp.node]) {
      int v = i[0], w = temp.dist + i[1];
      if (!visited[v] && w < distances[v]) {
        distances[v] = w;
        p.push(Node(v, w));
      }
    }
  }
  for (auto &i : distances) {
    cout << i << " ";
  }
  cout << endl;
}