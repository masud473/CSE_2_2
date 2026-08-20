#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Point {
public:
  double x, y;
  Point(double a, double b) : x(a), y(b) {};
  Point() {}
  Point(vector<double> v) {
    this->x = v[0];
    this->y = v[1];
  }
  void operator=(const Point &other) {
    this->x = other.x;
    this->y = other.y;
  }
  bool operator==(const Point &other) {
    return this->x == other.x && this->y == other.y;
  }
  bool operator!=(const Point &other) {
    return this->x != other.x && this->y != other.y;
  }
  void print() { cout << this->x << "," << this->y << " "; }
};
vector<Point> ans;
double cmp(const Point &a, const Point &b, const Point &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
double dist(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) - (a.y - b.y) * (a.y - b.y);
}
int main() {
  vector<Point> arr = {{10, 0}, {-10, 0}, {0, 10}, {0, -10},
                       {0, 3},  {0, -3},  {3, 0},  {-3, 0}};
  Point p =
      *min_element(arr.begin(), arr.end(), [](const Point &a, const Point &b) {
        if (a.y == b.y) {
          return a.x < b.x;
        }
        return a.y < b.y;
      });
  sort(arr.begin(), arr.end(), [&p](const Point &a, const Point &b) {
    double ccw = cmp(a, b, p);
    if (ccw == 0) {
      return dist(a, p) < dist(b, p);
    }
    return ccw > 0;
  });

  for (int i = 0; i < arr.size(); i++) {
    while (ans.size() > 1 &&
           cmp(*(ans.end() - 2), *(ans.end() - 1), arr[i]) <= 0) {
      ans.pop_back();
    }
    ans.push_back(arr[i]);
  }
  for (auto &i : ans) {
    i.print();
  }
}