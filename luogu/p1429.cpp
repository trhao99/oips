#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
const int N = 2e5 + 2;
const double INF = numeric_limits<double>::max();
int midScope[N];
struct node {
  double x, y;
} nodes[N];
double distance(int leftIndex, int rightIndex) {
  return sqrt(pow(nodes[leftIndex].x - nodes[rightIndex].x, 2) +
              pow(nodes[leftIndex].y - nodes[rightIndex].y, 2));
}
double merge(int leftIndex, int rightIndex) {
  double dis = INF;
  if (leftIndex == rightIndex)
    return dis;
  if (fabs(leftIndex - rightIndex) == 1)
    return distance(leftIndex, rightIndex);
  int midIndex = leftIndex + ((rightIndex - leftIndex) >> 1);
  double lm = merge(leftIndex, midIndex);
  double mr = merge(midIndex + 1, rightIndex);
  dis = min(lm, mr);
  int t = 0;
  for (int i = leftIndex; i <= rightIndex; i++) {
    if (fabs(nodes[i].x - nodes[midIndex].x) < dis) {
      midScope[t++] = i;
    }
  }
  sort(midScope, midScope + t,
       [](const int &a, const int &b) { return nodes[a].y < nodes[b].y; });
  double tmp;
  for (int i = 0; i < t; i++) {
    for (int j = i + 1;
         j < t && fabs(nodes[midScope[j]].y - nodes[midScope[i]].y) < dis;
         j++) {
      tmp = distance(midScope[i], midScope[j]);
      if (tmp < dis)
        dis = tmp;
    }
  }
  return dis;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].x >> nodes[i].y;
  }
  sort(nodes, nodes + n,
       [](const node &a, const node &b) { return a.x < b.x; });

  printf("%.4lf", merge(0, n - 1));
  return 0;
}