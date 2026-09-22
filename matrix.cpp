#include <bits/stdc++.h>
#include <cmath>
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
    return {{a[0][0] * b[0][0]}};
  }
  int n = a.size();
  n /= 2;
  vector<vector<int>> a11(n, vector<int>(n)), a12(n, vector<int>(n)),
      a21(n, vector<int>(n)), a22(n, vector<int>(n)), b11(n, vector<int>(n)),
      b12(n, vector<int>(n)), b21(n, vector<int>(n)), b22(n, vector<int>(n)),
      c11, c12, c21, c22, c(a.size(), vector<int>(a[0].size()));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a11[i][j] = a[i][j], a12[i][j] = a[i][j + n], a21[i][j] = a[i + n][j],
      a22[i][j] = a[i + n][j + n], b11[i][j] = b[i][j], b12[i][j] = b[i][j + n],
      b21[i][j] = b[i + n][j], b22[i][j] = b[i + n][j + n];
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
class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>> &mat1,
                               vector<vector<int>> &mat2) {
    int n = mat1.size();
    int m = ceil(log((double)n) / log(2));
    m = pow(2, m);
    vector<vector<int>> a(m, vector<int>(m)), b(m, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = mat1[i][j];
        b[i][j] = mat2[i][j];
      }
    }
    vector<vector<int>> c = ::multiply(a, b);
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = c[i][j];
      }
    }
    return d;
  }
};