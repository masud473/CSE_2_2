#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Box {
public:
  int start, end;
  Box(int a, int b) : start(a), end(b) {}
  Box() {}
  bool operator<(const Box &other) const { return this->end < other.end; }
};

int main() {
  vector<int> start = {1, 2, 0, 7, 8, 5};
  vector<int> end = {4, 4, 6, 10, 9, 7};
  vector<Box> arr;
  for (int i = 0; i < end.size(); i++) {
    arr.push_back(Box(start[i], end[i]));
  }
  sort(arr.begin(), arr.end());
  vector<Box> ans;
  int limit = -1;
  for (auto i : arr) {
    if (limit <= i.start) {
      ans.push_back(i);
      limit = i.end;
    }
  }
  for (auto &i : ans) {
    cout << i.start << " " << i.end << "\n";
  }
}