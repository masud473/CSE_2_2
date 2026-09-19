#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> parents;
class Edge {
public:
  int u, v, w;
  Edge(int a, int b, int c) : u(a), v(b), w(c) {}
  Edge() {}
  bool operator<(const Edge &other) const { return this->w < other.w; }
};

int find(int u) {
  if (parents[u] == u) {
    return u;
  }
  return parents[u] = find(parents[u]);
}
int main() {
  // Graph with V = 5 (nodes 0 to 4)
  int V = 5;

  vector<Edge> edges = {Edge(0, 1, 2), Edge(0, 3, 6), Edge(1, 2, 3),
                        Edge(1, 3, 8), Edge(1, 4, 5), Edge(2, 4, 7),
                        Edge(3, 4, 9)};
  for (int i = 0; i < V; i++) {
    parents.push_back(i);
  }
  sort(edges.begin(), edges.end());
  vector<Edge> ans;
  for (auto i : edges) {
    if (find(i.u) != find(i.v)) {
      parents[i.v] = parents[i.u];
      ans.push_back(i);
    }
  }
  for (auto i : parents) {
    cout << i << " ";
  }
  cout << '\n';
  for (auto &i : ans) {
    cout << i.u << " " << i.v << " " << i.w << '\n';
  }
}