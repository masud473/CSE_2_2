#include <bits/stdc++.h>

using namespace std;
pair<int, int> minmax(vector<int> &arr, int start, int end) {
  if (start == end) {
    return pair<int, int>(arr[start], arr[end]);
  }
  int mid = (start + end) / 2;
  pair<int, int> left = minmax(arr, start, mid);
  pair<int, int> right = minmax(arr, mid + 1, end);
  return pair<int, int>(min(left.first, right.first),
                        max(left.second, right.second));
}
int main() {
  vector<int> arr = {3, 5, 2, 7, 1, 8, 3, 5};
  pair<int, int>ans=minmax(arr, 0, arr.size()-1);
  cout<<ans.first<<" "<<ans.second;
  cout << endl;
  return 0;
}