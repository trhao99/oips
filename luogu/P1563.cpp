#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
struct person {
  string name;
  int orient; // 内 0 ,外 1
};
int main() {
  vector<person> ps;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    person p;
    cin >> p.orient >> p.name;
    if (p.orient == 0)
      p.orient = -1;
    ps.push_back(p);
  }
  // 内(-1),左(-1) +
  // 外(+1),左(-1) -
  //  内(-1)，右(+1) -
  //  外(+1),右(+1) +
  int lr, step, dur_index = 0, t;
  for (int i = 0; i < m; i++) {
    cin >> lr >> step;
    if (lr == 0)
      lr = -1;
    if (dur_index - lr * ps[dur_index].orient * step < 0) {
      dur_index += ps.size();
    }
    dur_index = (dur_index  - lr * ps[dur_index % n].orient * step) % n;
  }
  printf("%s", ps[dur_index].name.c_str());
}