#include <bits/stdc++.h>

using namespace std;

int main() {
  long long h = 293913517, a = 156431, m = 467107951;
  cout << (h * h) % m * ((a % m) % m) << endl;
  cout << h * h << endl;
  cout << (h * h) % m << endl;
  cout << a % m << endl;
}