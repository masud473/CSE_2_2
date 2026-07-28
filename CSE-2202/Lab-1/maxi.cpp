
#include <bits/stdc++.h>

using namespace std;
int minmax(vector<int> &arr, int start, int end) {
  if (start == end) {
    return arr[start];
  }
  int mid = (start + end) / 2;
  int left = minmax(arr, start, mid);
  int right = minmax(arr, mid + 1, end);
  return max(left,right);
}
int main() {
  vector<int> arr = {3, 5, 2, 7, 1, 8, 3, 5};
  int ans=minmax(arr, 0, arr.size()-1);
  cout<<ans<<endl;
  return 0;
}