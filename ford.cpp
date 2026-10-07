#include <bits/stdc++.h>
#include <vector>
using namespace std;
int INF = 1e8;
class Solution {
public:
  vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
    // Code here
    vector<int> dist(V, INF);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
      for (auto &j : edges) {
        int u = j[0], v = j[1], w = j[2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
        }
      }
    }
    for (auto &j : edges) {
      int u = j[0], v = j[1], w = j[2];
      if (dist[u] != INF && dist[u] + w < dist[v]) {
        return {-1};
      }
    }
    return dist;
  }
};
