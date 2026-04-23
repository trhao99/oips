#include <bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const int N = 200;
int dur_num[2] = {0, 1};
int main() {
  string line;
  int num, n, flag = 0;
  vector<int> numbers;
  getline(cin, line);
  stringstream ss(line);

  while (ss >> num) {
    numbers.push_back(num);
  }
  n = numbers[0];
  int cur_j = 0;
  for (int i = 1; i < numbers.size(); i++) {
    int n1 = numbers[i];
    for (int j = 0; j < n1; j++) {
      printf("%d", dur_num[flag]);
      if (cur_j == n - 1)
        printf("\n");
      cur_j = (cur_j + 1) % n;
    }
    flag = (flag + 1) % 2;
  }
  return 0;
}