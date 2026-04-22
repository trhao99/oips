#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3 - (i + 1); j++) {
      cout << " ";
    }
    for (int k = 0; k < 2 * i + 1; k++) {
      cout << c;
    }
    cout << endl;
  }
}