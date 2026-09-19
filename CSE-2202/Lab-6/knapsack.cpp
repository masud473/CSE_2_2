#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
class Box {
public:
  double price, wt;
  Box(double a, double b) : price(a), wt(b) {}
  Box() {}
  bool operator<(const Box &other) const {
    return this->price * other.wt < this->wt * other.price;
  }
};

int main() {
  vector<double> wt = {1, 2, 5, 2, 10, 32};
  vector<double> price = {123, 231, 535, 4546, 23, 120};
  priority_queue<Box> p;
  for (int i = 0; i < wt.size(); i++) {
    p.push(Box(price[i], wt[i]));
  }
  double total_wt = 12;
  double profit = 0;
  while (!p.empty() && total_wt > 0) {
    Box temp = p.top();
    p.pop();
    double amount = min(temp.wt, total_wt);
    total_wt -= amount;
    profit += temp.price * (amount / temp.wt);
  }
  cout << profit << '\n';
}