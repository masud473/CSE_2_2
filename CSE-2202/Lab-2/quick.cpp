#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>
#include <vector>
using namespace std;
int pivot(vector<int> &arr, int start, int end) {
  int i = start + 1, j = end;
  int pivot_val = arr[start];
  while (i <= j) {
    while (i <= end && arr[i] < pivot_val) {
      i++;
    }
    while (j > start && arr[j] >= pivot_val) {
      j--;
    }
    if (i < j) {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[j], arr[start]);
  return j;
}
void divide(vector<int> &arr, int i, int j) {
  if (i >= j) {
    return;
  }
  int width = j - i + 1;
  int sudo = i + (rand() % width);
  swap(arr[i], arr[sudo]);
  int point = pivot(arr, i, j);
  divide(arr, i, point - 1);
  divide(arr, point + 1, j);
}
int main() {
  vector<int> arr = {3, 5, 2, 5, 6, 2, 6, 3, 8, 45, 34, 23, 12};
  srand(time(0));

  int n = arr.size();
  divide(arr, 0, n - 1);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}