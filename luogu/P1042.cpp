#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
struct game {
  int mine = 0, other = 0;
};
int main() {
  vector<game> games11, games21;
  string s;
  game dur11, dur21;
  bool flag = true;
  while (flag) {
    getline(cin, s);
    for (char c : s) {
      if (c == 'W') {
        dur11.mine++;
        dur21.mine++;
      } else if (c == 'L') {
        dur11.other++;
        dur21.other++;
      } else if (c == 'E') {
        games11.push_back(dur11);
        games21.push_back(dur21);
        flag = false;
        break;
      }
      if (max(dur11.mine, dur11.other) >= 11 &&
          abs(dur11.mine - dur11.other) >= 2) {
        games11.push_back(dur11);
        dur11.mine = 0;
        dur11.other = 0;
      }
      if (max(dur21.mine, dur21.other) >= 21 &&
          abs(dur21.mine - dur21.other) >= 2) {
        games21.push_back(dur21);
        dur21.mine = 0;
        dur21.other = 0;
      }
    }
  }
  for (game g : games11) {
    printf("%d:%d\n", g.mine, g.other);
  }
  printf("\n");
  for (game g : games21) {
    printf("%d:%d\n", g.mine, g.other);
  }
  return 0;
}