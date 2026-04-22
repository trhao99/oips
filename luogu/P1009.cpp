#include <bits/stdc++.h>
#define LEN 90
using namespace std;
void clear(int a[]) {
  for (int i = 0; i < LEN; ++i)
    a[i] = 0;
}
void add(int a[], int b[], int c[]) {
  clear(c);

  // 高精度实现中，一般令数组的最大长度 LEN 比可能的输入大一些
  // 然后略去末尾的几次循环，这样一来可以省去不少边界情况的处理
  // 因为实际输入不会超过 1000 位，故在此循环到 LEN - 1 = 1003 已经足够
  for (int i = 0; i < LEN - 1; ++i) {
    // 将相应位上的数码相加
    c[i] += a[i] + b[i];
    if (c[i] >= 10) {
      // 进位
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}
void mul(int a[], int b[], int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    // 这里直接计算结果中的从低到高第 i 位，且一并处理了进位
    // 第 i 次循环为 c[i] 加上了所有满足 p + q = i 的 a[p] 与 b[q] 的乘积之和
    // 这样做的效果和直接进行上图的运算最后求和是一样的，只是更加简短的一种实现方式
    for (int j = 0; j <= i; ++j)
      c[i] += a[j] * b[i - j];

    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}
void val_copy(int a[], int b[]) {
  for (int i = 0; i < LEN; i++) {
    a[i] = b[i];
  }
}
int main() {
  int res[LEN], cur[LEN], n, t[LEN], _tmp[LEN];
  cin >> n;
  clear(res);
  clear(cur);
  clear(t);
  clear(_tmp);
  cur[0] = 1;
  for (int i = 1; i <= n; i++) {
    t[0] = i;
    val_copy(_tmp, cur);
    // cur *= i;
    mul(_tmp, t, cur);
    // res += cur;
    val_copy(_tmp, res);
    add(_tmp, cur, res);
  }
  bool first_non_zero = false;
  for (int i = LEN - 1; i >= 0; i--) {
    if(res[i]!=0 && !first_non_zero) first_non_zero = true; 
    if(res[i] == 0 && !first_non_zero) continue;
    printf("%d", res[i]);
  }
  return 0;
}