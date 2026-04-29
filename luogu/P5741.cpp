#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int N = 1e3;
struct student {
  string name;
  int y, s, w, sum_score;
} students[N];
struct sgroup {
  string first, second;
};
vector<sgroup> res;
bool sjld(student s1, student s2) {
  return abs(s1.sum_score - s2.sum_score) <= 10 && abs(s1.y - s2.y) <= 5 &&
         abs(s1.s - s2.s) <= 5 && abs(s1.w - s2.w) <= 5;
}
void resolve(int n) {
  if (n == 0)
    return;
  for (int i = 0; i < n; i++) {
    if (sjld(students[i], students[n])) {
      sgroup s;
      s.first = students[i].name;
      s.second = students[n].name;
      res.push_back(s);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> students[i].name >> students[i].y >> students[i].s >> students[i].w;
    students[i].sum_score = students[i].y + students[i].s + students[i].w;
    resolve(i);
  }
  sort(res.begin(), res.end(), [](sgroup s1, sgroup s2) {
    if (s1.first == s2.first) {
      return s1.second < s2.second;
    } else {
      return s1.first < s2.first;
    }
  });
  for (sgroup s : res) {
    printf("%s %s\n", s.first.c_str(), s.second.c_str());
  }
  return 0;
}