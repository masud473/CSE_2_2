#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int key(int val, int div) { return (val / div) % 10; }
void radix_sort(vector<int> &arr, int div, int n) {
  vector<int> radix(10);
  for (auto i : arr) {
    radix[key(i, div)]++;
  }
  for (int i = 1; i < 10; i++) {
    radix[i] += radix[i - 1];
  }
  if (radix[0] == n) {
    return;
  }
  vector<int> temp(n);
  for (int i = n - 1; i >= 0; i--) {
    temp[--radix[key(arr[i], div)]] = arr[i];
  }
  arr = temp;
  return;
}

int main() {
  vector<int> arr = {3, 5, 2, 5, 6, 2, 6, 3, 8, 45, 34, 23, 12};
  int n = arr.size();
  int max_val = *max_element(arr.begin(), arr.end());
  int d = 0;
  while (max_val) {
    max_val /= 10;
    d++;
  }
  int div = 1;
  for (int i = 0; i < d; i++) {
    radix_sort(arr, div, n);
    div *= 10;
  }
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}