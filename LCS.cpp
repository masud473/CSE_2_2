#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int solver(vector<vector<int>> &dp, string &a, string &b, int i, int j, int n,
             int m) {
    if (i == n || j == m) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    int ans = 0;
    if (a[i] == b[j]) {
      ans = 1 + solver(dp, a, b, i + 1, j + 1, n, m);
    } else {
      ans = max(solver(dp, a, b, i + 1, j, n, m),
                solver(dp, a, b, i, j + 1, n, m));
    }
    return dp[i][j] = ans;
  }
  int lcs(string &s1, string &s2) {
    // code here
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<int>> map(n + 1, vector<int>(m + 1, -1));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {

        if (s1[i] == s2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        } else
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    int i = 0, j = 0;
    string ans;
    while (i < n && j < m) {
      if (s1[i] == s2[j]) {
        ans.push_back(s1[i]);
        i++, j++;
      } else {
        if (dp[i + 1][j] > dp[i][j + 1]) {
          i++;
        } else {
          j++;
        }
      }
    }
    cout << ans << '\n';
    return dp[0][0];
  }
};
