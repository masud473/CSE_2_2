#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int V = 5;
  vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {1, 2, 2}, {1, 3, 5},
                               {2, 3, 2}, {2, 4, 1}, {3, 4, 3}};

  vector<int> dist(V, 1e7 + 7);
  dist[0] = 0;
  for (int i = 0; i < V - 1; i++) {
    for (auto &j : edges) {
      int u = i = j[0], v = j[1], w = j[2];
      dist[v] = min(dist[v], dist[u] + w);
    }
  }
  for (auto i : dist) {
    cout << i << " ";
  }
}