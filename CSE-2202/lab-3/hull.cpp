#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;
vector<vector<int>> ans;
int side(vector<int> a, vector<int> b, vector<int> p) {
  return (b[0] - a[0]) * (p[1] - a[1]) - (b[1] - a[1]) * (p[0] - a[0]);
}
int height(vector<int> a, vector<int> b, vector<int> p) {
  return abs(side(a, b, p));
}
int hull_point(vector<vector<int>> &arr, vector<int> &a, vector<int> &b) {
  int i = 0;
  for (int j = 1; j < arr.size(); j++) {
    if (height(a, b, arr[j]) > height(a, b, arr[i])) {
      i = j;
    }
  }
  return i;
}

void hull(vector<vector<int>> &arr, vector<int> &a, vector<int> &b) {
  if (arr.empty()) {
    return;
  }
  int pivot = hull_point(arr, a, b);
  vector<int> pivot_point = arr[pivot];
  ans.push_back(pivot_point);
  vector<vector<int>> top_hull, bottom_hull;
  for (auto &i : arr) {
    if (side(a, pivot_point, i) > 0) {
      top_hull.push_back(i);
    } else if (side(pivot_point, b, i) > 0) {
      bottom_hull.push_back(i);
    }
  }
  hull(top_hull, a, pivot_point);
  hull(bottom_hull, pivot_point, b);
}
int main() {
  int x = height({-10, 0}, {10, 0}, {0, -9});
  vector<vector<int>> arr = {{10, 0}, {-10, 0}, {0, 10}, {0, -10},
                             {0, 3},  {0, -3},  {3, 0},  {-3, 0}};
  sort(arr.begin(), arr.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
  vector<vector<int>> top_hull, bottom_hull;
  vector<int> a = arr[0], b = arr.back();
  for (auto &i : arr) {
    if (side(a, b, i) > 0) {
      top_hull.push_back(i);
    } else if (side(b, a, i) > 0) {
      bottom_hull.push_back(i);
    }
  }

  ans.push_back(a);
  ans.push_back(b);
  hull(top_hull, a, b);
  hull(bottom_hull, b, a);
  for (auto &i : ans) {
    cout << i[0] << " " << i[1] << '\n';
  }
  return 0;
}