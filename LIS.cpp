#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  int solve(vector<int> &dp, vector<int> &arr, int i, int n) {
    if (i == n)
      return 0;
    if (dp[i] != -1) {
      return dp[i];
    }
    int ans = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[i] < arr[j]) {
        ans = max(ans, 1 + solve(dp, arr, j, n));
      }
    }
    return dp[i] = ans;
  }
  vector<int> getLIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> next(n, -1);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] < arr[j] && 1 + dp[j] > dp[i]) {
          dp[i] = 1 + dp[j];
          next[i] = j;
        }
      }
    }
    int start = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> ans;
    while (start != -1) {
      ans.push_back(arr[start]);
      start = next[start];
    }
    return ans;
  }
};