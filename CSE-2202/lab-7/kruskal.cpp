#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int find_parent(vector<int> &parents, int node) {
  if (parents[node] == node) {
    return node;
  }
  return parents[node] = find_parent(parents, parents[node]);
}
int kruskalsMST(int V, vector<vector<int>> &edges) {
  sort(edges.begin(), edges.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2];
       });
  vector<int> parents(V);
  vector<int> sizes(V, 1);
  for (int i = 0; i < V; i++) {
    parents[i] = i;
  }
  int sum = 0;
  for (auto &i : edges) {
    int par_u = find_parent(parents, i[0]);
    int par_v = find_parent(parents, i[1]);
    if (par_u != par_v) {
      if (sizes[par_u] > sizes[par_v]) {
        parents[par_v] = par_u;
        sizes[par_u] += sizes[par_v];
      } else {
        parents[par_u] = par_v;
        sizes[par_v] += sizes[par_u];
      }
      sum += i[2];
    }
  }
  return sum;
}
int main() {
  int V = 5;
  vector<vector<int>> edges = {
      {0, 1, 4},
      {0, 2, 1},
      {1, 2, 2},
      {1, 3, 5},
      {2, 3, 2},
      {2, 4, 1},
      {3, 4, 3}
  };

  cout << kruskalsMST(V, edges) << "\n";
  return 0;
}
