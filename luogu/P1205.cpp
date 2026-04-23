#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char m1_before[10][10], m1_after[10][10], m1_copy[10][10];
bool eq(char a1[10][10], char a2[10][10], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a1[i][j] != a2[i][j])
        return false;
    }
  }
  return true;
}
void copy_m(char a1[10][10], char copied[10][10], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      copied[i][j] = a1[i][j];
    }
  }
}
void turn(int n) {
  char t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      t = m1_before[i][j];
      m1_before[i][j] = m1_before[i][n - 1 - j];
      m1_before[i][n - 1 - j] = t;
    }
  }
}
void spin90(int n) {
  char t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      t = m1_before[i][j];
      m1_before[i][j] = m1_before[j][i];
      m1_before[j][i] = t;
    }
  }
  turn(n);
}
void spin180(int n) {
  spin90(n);
  spin90(n);
}
void spin270(int n) {
  spin90(n);
  spin90(n);
  spin90(n);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m1_before[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m1_after[i][j];
    }
  }
  copy_m(m1_before, m1_copy, n);
  spin90(n);
  if (eq(m1_before, m1_after, n)) {
    printf("1");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  spin180(n);
  if (eq(m1_before, m1_after, n)) {
    printf("2");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  spin270(n);
  if (eq(m1_before, m1_after, n)) {
    printf("3");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  turn(n);
  if (eq(m1_before, m1_after, n)) {
    printf("4");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  turn(n);
  spin90(n);
  if (eq(m1_before, m1_after, n)) {
    printf("5");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  turn(n);
  spin180(n);
  if (eq(m1_before, m1_after, n)) {
    printf("5");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  turn(n);
  spin270(n);
  if (eq(m1_before, m1_after, n)) {
    printf("5");
    return 0;
  }
  copy_m(m1_copy, m1_before, n);

  if (eq(m1_before, m1_after, n)) {
    printf("6");
    return 0;
  }
  printf("7");
  return 0;
}