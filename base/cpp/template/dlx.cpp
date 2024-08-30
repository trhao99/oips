#include <bits/stdc++.h>
const int N = 500 + 10;
int n, m, ans;
int stk[N];

int read() {  // 快读
  int x = 0, f = 0, ch;
  while (!isdigit(ch = getchar())) f |= ch == '-';
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}

struct DLX {
  static const int MAXSIZE = 1e5 + 10;
  int n, m, tot, first[MAXSIZE + 10], siz[MAXSIZE + 10];
  int L[MAXSIZE + 10], R[MAXSIZE + 10], U[MAXSIZE + 10], D[MAXSIZE + 10];
  int col[MAXSIZE + 10], row[MAXSIZE + 10];

  void build(const int &r, const int &c) {  // 进行build操作
    n = r, m = c;
    for (int i = 0; i <= c; ++i) {
      L[i] = i - 1, R[i] = i + 1;
      U[i] = D[i] = i;
    }
    L[0] = c, R[c] = 0, tot = c;
    memset(first, 0, sizeof(first));
    memset(siz, 0, sizeof(siz));
  }

  void insert(const int &r, const int &c) {  // 进行insert操作
    col[++tot] = c, row[tot] = r, ++siz[c];
    D[tot] = D[c], U[D[c]] = tot, U[tot] = c, D[c] = tot;
    if (!first[r])
      first[r] = L[tot] = R[tot] = tot;
    else {
      R[tot] = R[first[r]], L[R[first[r]]] = tot;
      L[tot] = first[r], R[first[r]] = tot;
    }
  }

  //将c这个元素，所在列不为0的元素的所在行删掉（除c所在行）,x算法要用remove
  void remove(const int &c) {  // 进行remove操作
    int i, j;
    L[R[c]] = L[c], R[L[c]] = R[c];
    for (i = D[c]; i != c; i = D[i])
      for (j = R[i]; j != i; j = R[j])
        U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
  }

  // 虽然 c元素及其，与他关联的列的所在行都被删除，但删除方式是原本元素的上一个元素的D元素不指向他了，他的U元素依然可以指向原本的U元素。
  void recover(const int &c) {  // 进行recover操作
    int i, j;
    for (i = U[c]; i != c; i = U[i])
      for (j = L[i]; j != i; j = L[j]) U[D[j]] = D[U[j]] = j, ++siz[col[j]];
    L[R[c]] = R[L[c]] = c;
  }

  bool dance(int dep) {  // dance
    if (!R[0]) {
      ans = dep;
      return 1;
    }
    int i, j, c = R[0];
    for (i = R[0]; i != 0; i = R[i])//筛选出列元素最小的列,这样第一层for循环的次数少了
      if (siz[i] < siz[c]) c = i;
    remove(c);//删除列元素最小的列,及其列所在的行
    for (i = D[c]; i != c; i = D[i]) { //从上往下依次遍历, 首先选择c元素所在列，从上往下的第一个非0元素所在行，为第一个选择行
      stk[dep] = row[i];
      for (j = R[i]; j != i; j = R[j]) remove(col[j]);//已经选了元素i了，则元素i所在行,所有为1的列的对应元素的所在列有同为1的解(也就是以1行)要删掉。
      if (dance(dep + 1)) return 1;//继续寻找下一步解，若return 1则说明已经递归到最深处找到最终解,直接返回上一层
      for (j = L[i]; j != i; j = L[j]) recover(col[j]);//选择i这一行作为解的一部分,最终无法构成完整解，回退,进入下一个for循环,i=D[i]选择i所在行的下一非0行作为解的一部分，尝试求解
    }
    recover(c);//回退，说明上一层找错解了，return 0让上一层回退，i=D[i]搜寻下一个解
    return 0;
  }
} solver;

int main() {
  n = read(), m = read();
  solver.build(n, m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x = read();
      if (x) solver.insert(i, j);
    }
  solver.dance(1);
  if (ans)
    for (int i = 1; i < ans; ++i) printf("%d ", stk[i]);
  else
    puts("No Solution!");
  return 0;
}
