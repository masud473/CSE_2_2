#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<vector<int>> sum(vector<vector<int>> a, vector<vector<int>> b) {
  vector<vector<int>> c(a.size(), vector<int>(a[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}
vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
  if (a.size() == 1) {
    return vector<vector<int>>{{a[0][0] * b[0][0]}};
  }
  int n = a.size() / 2;
  vector<vector<int>> a11(n, vector<int>(n)), a12(n, vector<int>(n)),
      a21(n, vector<int>(n)), a22(n, vector<int>(n)), b11(n, vector<int>(n)),
      b12(n, vector<int>(n)), b21(n, vector<int>(n)), b22(n, vector<int>(n)),
      c11, c12, c21, c22, c(a.size(), vector<int>(a[0].size()));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a11[i][j] = a[i][j];
      a12[i][j] = a[i][j + n];
      a21[i][j] = a[i + n][j];
      a22[i][j] = a[i + n][j + n];
      b11[i][j] = b[i][j];
      b12[i][j] = b[i][j + n];
      b21[i][j] = b[i + n][j];
      b22[i][j] = b[i + n][j + n];
    }
  }
  c11 = sum(multiply(a11, b11), multiply(a12, b21));
  c12 = sum(multiply(a11, b12), multiply(a12, b22));
  c21 = sum(multiply(a21, b11), multiply(a22, b21));
  c22 = sum(multiply(a21, b12), multiply(a22, b22));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = c11[i][j];
      c[i][j + n] = c12[i][j];
      c[i + n][j] = c21[i][j];
      c[i + n][j + n] = c22[i][j];
    }
  }
  return c;
}

int main() {
  vector<vector<int>> v1 = {
      {1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}, {11, 12, 13, 14}};
  vector<vector<int>> v2 = {
      {1, 2, 3, 1}, {4, 5, 6, 2}, {7, 8, 9, 3}, {12, 2, 23, 43}};
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
  cout << endl;
  vector<vector<int>> v4 = multiply(v1, v2);
  for (auto &i : v4) {
    for (auto &j : i) {
      cout << j << " ";
    }
    cout << '\n';
  }
}