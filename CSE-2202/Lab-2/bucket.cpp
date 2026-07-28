#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
int key(int val, int div) { return (val / div) % 10; }
void insertion_sort(vector<int> &arr, int start, int n) {

  for (int i = n - 1; i >= start; i--) {
    for (int j = i; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      } else {
        break;
      }
    }
  }
}
void bucket_sort(vector<int> &arr, int buckets) {
  vector<vector<int>> bucket(buckets);
  int max_val = *max_element(arr.begin(), arr.end());
  for (auto i : arr) {
    int index = (i * buckets) / (max_val + 1);
    bucket[index].push_back(i);
  }
  for (auto &vec : bucket) {
    insertion_sort(vec, 0, vec.size());
  }
  int k = 0;
  for (auto &vec : bucket) {
    for (auto i : vec) {
      arr[k++] = i;
    }
  }
  return;
}

int main() {
  vector<int> arr = {3, 5, 2, 5, 6, 2, 6, 3, 8, 45, 34, 23, 12};
  int n = arr.size();

  bucket_sort(arr, 20);

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}