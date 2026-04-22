#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main() {
  double m, h, bmi;
  cin >> m >> h;
  bmi = m / (h * h);
  if (bmi < 18.5) {
    printf("Underweight");
  }
  if (bmi >= 18.5 && bmi < 24) {
    printf("Normal");
  }
  if (bmi >= 24) {
    cout << setprecision(6);
    cout << bmi << endl << "Overweight";
  }
  return 0;
}