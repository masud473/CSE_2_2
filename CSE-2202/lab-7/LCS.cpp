#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> dp(1000, vector<int>(1000, -1));
int LCS(string &a, string &b, int i, int j, int n, int m) {
  if (i == n || j == m) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (a[i] == b[j]) {
    return dp[i][j] = 1 + LCS(a, b, i + 1, j + 1, n, m);
  } else {
    return dp[i][j] = max(LCS(a, b, i + 1, j, n, m), LCS(a, b, i, j + 1, n, m));
  }
}
int main() {
  string a = "thisissomething", b = "smetho";

  cout << LCS(a, b, 0, 0, (int)a.size(), (int)b.size());
}