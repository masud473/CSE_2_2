#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
int find(vector<int> &parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = find(parent, parent[node]);
}
class Solution {
public:
  int kruskalsMST(int V, vector<vector<int>> &edges) {
    // code here
    sort(
        edges.begin(), edges.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2]; });
    vector<int> parent(V);
    vector<int> size(V, 1);
    for (int i = 0; i < V; i++) {
      parent[i] = i;
    }
    int sum = 0;
    for (auto &i : edges) {
      int u = i[0], v = i[1], w = i[2];
      int x = find(parent, u);
      int y = find(parent, v);
      if (x != y) {
        sum += w;
        if (size[x] < size[y]) {
          size[y] += size[x];
          parent[x] = y;
        } else {
          size[x] += size[y];
          parent[y] = x;
        }
      }
    }
    return sum;
  }
};