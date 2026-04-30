#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
bool rules[5][5] = {{false, false, true, true, false},
                    {true, false, false, true, false},
                    {false, true, false, false, true},
                    {false, false, true, false, true},
                    {true, true, false, false, false}};
int main() {
  int n, na, nb, t, a_type, b_type, a_score = 0, b_score = 0;
  vector<int> a, b;
  cin >> n >> na >> nb;
  for (int i = 0; i < na; i++) {
    cin >> t;
    a.push_back(t);
  }
  for (int i = 0; i < nb; i++) {
    cin >> t;
    b.push_back(t);
  }
  for (int i = 0; i < n; i++) {
    a_type = a[i % a.size()];
    b_type = b[i % b.size()];
    if (a_type == b_type)
      continue;
    else {
      if (rules[a_type][b_type])
        a_score++;
      else
        b_score++;
    }
  }
  printf("%d %d", a_score, b_score);
  return 0;
}