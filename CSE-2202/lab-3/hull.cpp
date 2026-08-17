#include <bits/stdc++.h>
#include <cstdlib>
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
double cmp(Point &a, Point &b, Point &c) {
  return (b.y - c.y) * (b.x - a.x) - (b.x - c.x) * (b.y - a.y);
}
int pivot(vector<Point> &arr, Point &left, Point &right) {
  int i = 0;
  for (int j = 1; j < arr.size(); j++) {
    if (abs(cmp(left, right, arr[j])) > abs(cmp(left, right, arr[i]))) {
      i = j;
    }
  }
  return i;
}
void hull(vector<Point> &arr, Point &left, Point &right) {
  if (arr.empty()) {
    return;
  }
  Point p = arr[pivot(arr, left, right)];
  vector<Point> top, bottom;
  ans.push_back(p);
  for (auto &i : arr) {
    if (cmp(left, p, i) > 0) {
      top.push_back(i);
    } else if (cmp(p, right, i) > 0) {
      bottom.push_back(i);
    }
  }
  hull(top, left, p);
  hull(bottom, p, right);
}
int main() {
  vector<Point> arr = {{10, 0}, {-10, 0}, {0, 10}, {0, -10},
                       {0, 3},  {0, -3},  {3, 0},  {-3, 0}};
  Point left = arr[0], right = arr[0];
  for (auto &i : arr) {
    if (left.x > i.x) {
      left = i;
    } else if (left.x == i.x) {
      if (i.y > left.y) {
        left = i;
      }
    }
    if (right.x < i.x) {
      right = i;
    } else if (right.x == i.x) {
      if (i.y > right.y) {
        right = i;
      }
    }
  }
  ans.push_back(left);
  ans.push_back(right);
  vector<Point> top, bottom;
  for (auto &i : arr) {
    if (cmp(left, right, i) > 0) {
      top.push_back(i);
    }
  }
  hull(top, left, right);
  left = arr[0], right = arr[0];
  for (auto &i : arr) {
    if (left.x > i.x) {
      left = i;
    } else if (left.x == i.x) {
      if (i.y < left.y) {
        left = i;
      }
    }
    if (right.x < i.x) {
      right = i;
    } else if (right.x == i.x) {
      if (i.y < right.y) {
        right = i;
      }
    }
  }
  if (left != ans[0]) {
    ans.push_back(left);
  }
  if (right != ans[1]) {
    ans.push_back(right);
  }
  for (auto &i : arr) {
    if (cmp(right, left, i) > 0) {
      bottom.push_back(i);
    }
  }
  hull(bottom, right, left);
  for (auto &i : ans) {
    i.print();
  }
}