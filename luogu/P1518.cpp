#include <bits/stdc++.h>
#include <cstdio>
#include <tuple>
using namespace std;
const int N = 1e5;
int direct[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char m[10][10];
tuple<int, int, int> update_pos(int x, int y, int dir) {
  int new_x, new_y;
  new_x = x + direct[dir][0];
  new_y = y + direct[dir][1];
  if (new_x < 0 || new_x >= 10 || new_y < 0 || new_y >= 10) {
    dir = (dir + 1) % 4;
    return {x, y, dir};
  }
  if (m[new_x][new_y] == '*') {
    dir = (dir + 1) % 4;
    return {x, y, dir};
  }
  return {new_x, new_y, dir};
}
int main() {
  int f_x, f_y, c_x, c_y, c_dir = 0, f_dir = 0, step = 1;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> m[i][j];
      if (m[i][j] == 'F') {
        f_x = i;
        f_y = j;
      }
      if (m[i][j] == 'C') {
        c_x = i;
        c_y = j;
      }
    }
  }
  while (step < N) {
    // 更新ren
    tuple<int, int, int> f_res = update_pos(f_x, f_y, f_dir);
    f_x = get<0>(f_res);
    f_y = get<1>(f_res);
    f_dir = get<2>(f_res);
    // 更新niu
    tuple<int, int, int> c_res = update_pos(c_x, c_y, c_dir);
    c_x = get<0>(c_res);
    c_y = get<1>(c_res);
    c_dir = get<2>(c_res);
    // 对比是否位置一样
    if (c_x == f_x && c_y == f_y) {
      break;
    }
    step++;
  }
  if (step == N)
    step = 0;
  printf("%d", step);
  return 0;
}