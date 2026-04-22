#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main() {
  int surplus = 0, save = 0, t;
  for (int i = 0; i < 12; i++) {
    cin >> t;
    surplus += 300;
    int account = surplus - t;
    if (account < 0) {
      printf("-%d", i + 1);
      return 0;
    } else {
      if (account >= 100) {
        save += (account - account % 100);
        surplus = account % 100;
      } else {
        surplus = account;
      }
    }
    account = 0;
  }
  printf("%d", (int)(surplus + save * 1.2));
  return 0;
}