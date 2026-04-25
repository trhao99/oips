#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
using namespace std;
string s;
string reverse_calc_double(int start, int len) {
  int s_index = start;
  string res = "";
  while (s[s_index] == '0')
    s_index++;
  for (int i = start + len - 1; i >= s_index; i--) {
    // res = res * 10 + (s[i] - '0');
    res += s[i];
  }
  if(res=="") res = "0";
  return res;
}
string reverse_calc_int(int start, int len) {
  int end = start + len - 1;
  string res = "";
  while (s[end] == '0')
    end--;
  for (int i = end; i >= start; i--) {
    // res = res * 10 + (s[i] - '0');
    res += s[i];
  }
  if(res=="") res = "0";
  return res;
}
int main() {
  cin >> s;
  size_t point_pos, div_pos, percent_pos;
  point_pos = s.find(".");
  div_pos = s.find("/");
  percent_pos = s.find("%");
  if (point_pos != string::npos) {
    string int_part = reverse_calc_int(0, point_pos);
    string double_part =
        reverse_calc_double(point_pos + 1, s.size() - 1 - point_pos);
    printf("%s.%s", int_part.c_str(), double_part.c_str());
  } else if (div_pos != string::npos) {
    string fz_part = reverse_calc_int(0, div_pos);
    string fm_part = reverse_calc_int(div_pos + 1, s.size() - 1 - div_pos);
    printf("%s/%s", fz_part.c_str(), fm_part.c_str());
  } else if (percent_pos != string::npos) {
    string int_part = reverse_calc_int(0, percent_pos);
    printf("%s%%", int_part.c_str());
  } else {
    string int_part = reverse_calc_int(0, s.size());
    printf("%s", int_part.c_str());
  }
  return 0;
}