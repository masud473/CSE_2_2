#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  vector<int> merge = {2, 3, 9, 10, 4, 7};
  priority_queue<int, vector<int>, greater<int>> p;
  for (auto i : merge) {
    p.push(i);
  }
  int cost = 0;
  while (p.size() > 1) {
    int a = p.top();
    p.pop();
    int b = p.top();
    p.pop();
    cost += a + b;
    cout << "merging " << a << " " << b << " adding " << a + b << '\n';
    p.push(a + b);
  }
  cout << cost << '\n';
}