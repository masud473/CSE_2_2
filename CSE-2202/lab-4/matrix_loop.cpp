#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> v1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> v2 = {{1, 2, 3, 1}, {4, 5, 6, 2}, {7, 8, 9, 3}};
  int n = v1.size(), m = v1[0].size(), o = v2.size(), p = v2[0].size();
  vector<vector<int>> v3(n, vector<int>(p));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      v3[i][j] = 0;
      for (int k = 0; k < m; k++) {
        v3[i][j] += v1[i][k] * v2[k][j];
      }
    }
  }
  for (auto &i : v3) {
    for (auto &j : i) {
      cout << j << " ";
    }
    cout << '\n';
  }
}