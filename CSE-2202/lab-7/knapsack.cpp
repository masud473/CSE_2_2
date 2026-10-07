#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> dp(1000, vector<int>(1000, 0));
int knapsack(vector<int> &profit, vector<int> &wt, int capacity, int i, int n) {
  if (i == n || !capacity) {
    return 0;
  }
  if (dp[i][capacity] != -1) {
    return dp[i][capacity];
  }
  if (wt[i] <= capacity) {
    dp[i][capacity] =
        max(profit[i] + knapsack(profit, wt, capacity - wt[i], i + 1, n),
            knapsack(profit, wt, capacity, i + 1, n));
  } else {
    dp[i][capacity] = knapsack(profit, wt, capacity, i + 1, n);
  }
  return dp[i][capacity];
}
int main() {
  vector<int> profit = {60, 100, 120};
  vector<int> wt = {10, 20, 30};
  int capacity = 50;
  int n = wt.size();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= capacity; j++) {
      if (j >= wt[i]) {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - wt[i]] + profit[i]);
      } else {
        dp[i][j] = dp[i + 1][j];
      }
    }
  }
  cout << dp[0][capacity] << "\n";
  return 0;
}