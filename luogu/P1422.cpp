#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n <= 150)
    printf("%.1f", n * 0.4463);
  if (n >= 151 && n <= 400)
    printf("%.1f", 150 * 0.4463 + (n - 150) * 0.4663);
  if (n >= 401)
    printf("%.1f",
           150 * 0.4463 + (400 - 151 + 1) * 0.4663 + (n - 400) * 0.5663);
  return 0;
}