#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
// optimal merge pattern
// int minComputation(vector<int> &files) {
//   // code here
//   priority_queue<int, vector<int>, greater<int>> p(files.begin(),
//   files.end()); int sum = 0; while (p.size() > 1) {
//     int a = p.top();
//     p.pop();
//     int b = p.top();
//     p.pop();
//     sum += (a + b);
//     p.push(a + b);
//   }
//   return sum;
// }

// // kruskal's mst
// int find_parent(vector<int> &parents, int node) {
//   if (parents[node] == node) {
//     return node;
//   }
//   return parents[node] = find_parent(parents, parents[node]);
// }
// int kruskalsMST(int V, vector<vector<int>> &edges) {
//   // code here
//   sort(edges.begin(), edges.end(),
//        [](const vector<int> &a, const vector<int> &b) { return a[2] < b[2];
//        });
//   vector<int> parents(V);
//   vector<int> sizes(V, 1);
//   for (int i = 0; i < V; i++) {
//     parents[i] = i;
//   }
//   int sum = 0;
//   for (auto &i : edges) {
//     int par_u = find_parent(parents, i[0]);
//     int par_v = find_parent(parents, i[1]);
//     if (par_u != par_v) {
//       // cout<<par_u<<" "<<par_v<<"  ";
//       if (sizes[par_u] > sizes[par_v]) {
//         parents[par_v] = par_u;
//         sizes[par_u] += sizes[par_v];
//       } else {
//         parents[par_u] = par_v;
//         sizes[par_v] += sizes[par_u];
//       }
//       sum += i[2];
//     }
//   }
//   return sum;
// }

// activity selection
//  class Box {
//  public:
//    int start = 0, end = 0;
//    Box() {}
//    Box(int a, int b) : start(a), end(b) {}
//    bool operator<(const Box &other) const { return this->end < other.end; }
//  };

// int activitySelection(vector<int> &start, vector<int> &finish) {
//   vector<Box> v;
//   for (int i = 0; i < start.size(); i++) {
//     v.push_back(Box(start[i], finish[i]));
//   }
//   sort(v.begin(), v.end());
//   int prev_end = -1;
//   int count = 0;
//   for (auto &i : v) {
//     if (i.start >= prev_end) {
//       count++;
//       prev_end = i.end;
//     }
//   }
//   return count;
// }

// fractional knapsack
// class Box {
// public:
//   double val = 0, wt = 0;
//   Box() {}
//   Box(double a, double b) : val(a), wt(b) {}// fractions won't work unless
//   double bool operator<(const Box &other) const {
//     return this->val * other.wt > other.val * this->wt;
//   }
// };

// class Solution {
// public:
//   double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
//   {
//     double ans = 0;
//     vector<Box> v;
//     for (int i = 0; i < val.size(); i++) {
//       v.push_back(Box(val[i], wt[i]));
//     }
//     sort(v.begin(), v.end());
//     for (auto &i : v) {
//       double amount = min(i.wt, (double)capacity);// double is for fraction
//     //   cout<<i.val<<" "<<i.wt<<"  ";
//       ans += (i.val / i.wt) * amount;
//       capacity -= amount;
//       if (capacity<=0) {
//         return ans;
//       }
//     }
//     return ans;
//   }
// };

// job sequencing
// class Box {
// public:
//   int profit = 0, deadline = 0;
//   Box() {}
//   Box(int a, int b)
//       : profit(a), deadline(b) {}
//   bool operator<(const Box &other) const {
//     if (this->profit == other.profit) {
//       return this->deadline < other.deadline;// sort by deadline and profit
//     }
//     return this->profit > other.profit;
//   }
// };
// int find_slot(vector<int> &time, int date) {
//   if (time[date] == -1) {// time has passed
//     return -1;
//   } else if (time[date] == date) {
//     return --time[date];// there still is time, set the next available time
//     to previous time
//   }
//   return time[date] = find_slot(time, time[date]);// same as dsu, check
//   parents time and set time to new-parent time
// }
// class Solution {
// public:
//   vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
//     int jobs = 0;
//     int earning = 0;
//     vector<int> slots(*max_element(deadline.begin(), deadline.end()) + 1);
//     for (int i = 0; i < slots.size(); i++) {
//       slots[i] = i;
//     }
//     slots[0] = -1;// total n deadlines and 0th means -1 or null
//     vector<Box> v;
//     for (int i = 0; i < deadline.size(); i++) {
//       v.push_back(Box(profit[i], deadline[i]));
//     }
//     sort(v.begin(), v.end());
//     for (auto &i : v) {
//       if (find_slot(slots, i.deadline)!=-1) {
//         jobs++;
//         earning += i.profit;
//       }
//     }
//     return {jobs, earning};
//   }
// };

// Graham Scan
// class Point {
// public:
//   long long x = 0, y = 0;
//   Point() {}
//   Point(int a, int b) : x(a), y(b) {}
//   Point(const vector<int> &p) { x = p[0], y = p[1]; }
//   vector<int> vectorize() { return {(int)this->x, (int)this->y}; }
// };
// vector<Point> ans;

// bool ccw(const Point &a, const Point &b, const Point &c) {
//   return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x) > 0;
// }
// long long cmp(const Point &a, const Point &b, const Point &c) {
//   return (1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x));
// }
// long long dist(const Point &a, const Point &b) {
//   return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
// }
// class Solution {
// public:
//   vector<vector<int>> findConvexHull(vector<vector<int>> &points) {
//     // Code here

//     vector<Point> v(points.begin(), points.end());

//     Point a =
//         *min_element(v.begin(), v.end(), [](const Point &a1, const Point &a2) {
//           if (a1.y == a2.y) {
//             return a1.x < a2.x;
//           }
//           return a1.y < a2.y;
//         });
//     ans.clear();
//     sort(v.begin(), v.end(), [&a](const Point &b, const Point &c) {
//       long long x = cmp(a, b, c);
//       if (x == 0) {
//         return dist(a, b) < dist(a, c);
//       }
//       return x > 0;
//     });
//     for (auto &i : v) {
//       while (ans.size() >= 2) {
//         Point a = *(ans.end() - 2);
//         Point b = *(ans.end() - 1);
//         if (!ccw(a, b, i)) {
//           ans.pop_back();
//         } else {
//           break;
//         }
//       }
//       ans.push_back(i);
//     }
//     vector<vector<int>> p;
//     for (auto &i : ans) {
//       p.push_back(i.vectorize());
//     }

//     sort(p.begin(), p.end());
//     p.erase(unique(p.begin(), p.end()), p.end());
//     if (p.size() < 3) {
//       return {{-1}};
//     }
//     return p;
//   }
// };

// Quick Hull
// class Point {
// public:
//   int x = 0, y = 0;
//   Point() {}
//   Point(int a, int b) : x(a), y(b) {}
//   Point(const vector<int> &p) { x = p[0], y = p[1]; }
//   vector<int> vectorize() { return {this->x, this->y}; }
// };
// vector<Point> ans;

// bool is_above(Point &a, Point &b, Point &c) {
//   return 1LL*(b.x - a.x) * (c.y - a.y) - 1LL*(b.y - a.y) * (c.x - a.x) > 0;
// }
// long long  height(Point &a, Point &b, Point &c) {
//   return abs(1LL*(b.x - a.x) * (c.y - a.y) - 1LL*(b.y - a.y) * (c.x - a.x));
// }
// Point find_point(vector<Point> &hull, Point &a, Point &b) {
//   long long dist = 0;
//   Point p = a; // just select a cause dist is 0
//   for (auto &i : hull) {
//     long long x = height(a, b, i);
//     if (x > dist) {
//       p = i;
//       dist = x;
//     }
//   }
//   return p;
// }
// void build_hull(vector<Point> &hull, Point &a, Point &b) {
//   if (hull.empty()) {
//     return;
//   }
//   Point p = find_point(hull, a, b);
//   ans.push_back(p);
//   vector<Point> top, bottom;
//   for (auto &i : hull) {
//     if (is_above(a, p, i)) {
//       top.push_back(i);
//     }
//     if (is_above(p, b, i)) {
//       bottom.push_back(i);
//     }
//   }
//   build_hull(top, a, p);
//   build_hull(bottom, p, b);
// }

// class Solution {
// public:
//   vector<vector<int>> findConvexHull(vector<vector<int>> &points) {
//     // Code here

//     vector<Point> v(points.begin(), points.end());

//     Point a =
//         *max_element(v.begin(), v.end(), [](const Point &a1, const Point &a2) {
//           if (a1.x == a2.x) {
//             return a1.y > a2.y;
//           }
//           return a1.x < a2.x;
//         });
//     Point b =
//         *max_element(v.begin(), v.end(), [](const Point &a1, const Point &a2) {
//           if (a1.x == a2.x) {
//             return a1.y > a2.y;
//           }
//           return a1.x > a2.x;
//         });

//     ans.clear();
//     ans.push_back(a);
//     ans.push_back(b);
//     vector<Point> top, bottom;
//     for (auto &i : v) {
//       if (is_above(a, b, i)) {
//         top.push_back(i);
//       }
//       if (is_above(b, a, i)) {
//         bottom.push_back(i);
//       }
//     }
//     build_hull(top, a, b);
//     build_hull(bottom, b, a);
//     vector<vector<int>> p;
//     for (auto &i : ans) {
//       p.push_back(i.vectorize());
//     }
//     sort(p.begin(), p.end());
//     p.erase(unique(p.begin(), p.end()), p.end());
//     if (p.size() < 3) {
//       return {{-1}};
//     }
//     return p;
//   }
// };
