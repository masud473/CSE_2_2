#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void count_sort(vector<int> &arr) {
  int limit = 0;
  for (auto &i : arr) {
    limit = max(limit, i);
  }
  vector<int> cnt_arr(limit + 1);
  for (auto &i : arr) {
    cnt_arr[i]++;
  }
  int n = arr.size();
  for (int i = 1; i <= limit; i++) {
    cnt_arr[i] += cnt_arr[i - 1];
  }
  vector<int> temp(n);
  for (int i = n - 1; i >= 0; i--) {
    temp[--cnt_arr[arr[i]]] = arr[i];
  }
  arr = temp;
}
int main() {
  vector<int> arr = {3, 5, 2, 7, 1, 8, 3, 5};
  count_sort(arr);
  for (auto &i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}