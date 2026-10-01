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
  vector<vector<vector<int>>> adj = {
      {{1, 4}, {2, 1}},                 // Node 0
      {{0, 4}, {2, 2}, {3, 5}},         // Node 1
      {{0, 1}, {1, 2}, {3, 2}, {4, 1}}, // Node 2
      {{1, 5}, {2, 2}, {4, 3}},         // Node 3
      {{2, 1}, {3, 3}}                  // Node 4
  };

  priority_queue<Node> p;
  int sum = 0;
  p.push(Node(0, 0));
  vector<int> distances(adj.size(), 1e9 + 7);
  vector<bool> visited(adj.size());
  vector<int> parent(adj.size(), -1);
  distances[0] = 0;
  while (p.size()) {
    Node temp = p.top();
    p.pop();
    if (visited[temp.node]) {
      continue;
    }
    sum += temp.dist;
    visited[temp.node] = true;
    for (auto &i : adj[temp.node]) {
      int v = i[0], w = i[1];
      if (!visited[v] && w < distances[v]) {
        distances[v] = w;
        parent[v] = temp.node;
        p.push(Node(v, w));
      }
    }
  }
  for (int i = 0; i < adj.size(); i++) {
    cout << parent[i] << " -> " << i << " : " << distances[i] << endl;
  }
  cout << sum << endl;
}