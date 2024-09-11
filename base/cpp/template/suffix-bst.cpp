#include <bits/stdc++.h>
using namespace std;

// const int N = 8e5 + 5;
const int N = 20;
// const double INF = 1e18;
const double INF = 100;

void decode(char *s, int len, int mask) {
  for (int i = 0; i < len; ++i) {
    mask = (mask * 131 + i) % len;
    swap(s[i], s[mask]);
  }
}

int q, n, na;
char a[N], t[N];

// SuffixBST(SGT Ver)
// 后缀平衡树上的一个节点相当于原字符串的一个后缀
// 顺序加入，查询时将询问串翻转
// 以i结束的前缀，对应节点的编号为i
// 注意：不能写懒惰删除，否则可能会破坏树的结构
const double alpha = 0.75;
int root;
int sz[N], L[N], R[N];
double tag[N];
int buffer_size, buffer[N];

bool cmp(int x, int y) {
  if (t[x] != t[y])
    return t[x] < t[y];
  return tag[x - 1] < tag[y - 1];
}

void init() { root = 0; }

//lv left-value rv right-value
void new_node(int &rt, int p, double lv, double rv) {
  rt = p;
  sz[rt] = 1;
  tag[rt] = (lv + rv) / 2;
  L[rt] = R[rt] = 0; // 叶子节点的L,R值为0
}

// 维护大小 sz数组
void push_up(int x) {
  if (!x)
    return;
  // 当前节点的大小 = 左子树大小 + 右子树大小 + 1（当前节点）
  sz[x] = sz[L[x]] + 1 + sz[R[x]];
}

// 左 || 右 子树大小 超过整棵树的大小的alpha倍（0<alpha<1）则不平衡
bool balance(int rt) { return alpha * sz[rt] > max(sz[L[rt]], sz[R[rt]]); }

//中顺遍历节点存到buffer中
void flatten(int rt) {
  if (!rt)
    return;
  flatten(L[rt]);
  buffer[++buffer_size] = rt;
  flatten(R[rt]);
}

// 重新建rt的子树， 维护tag, sz, &rt, L[rt], R[rt]
void build(int &rt, int l, int r, double lv, double rv) {
  if (l > r) {
    rt = 0;
    return;
  }
  int mid = (l + r) >> 1;
  double mv = (lv + rv) / 2;

  rt = buffer[mid];
  tag[rt] = mv;
  build(L[rt], l, mid - 1, lv, mv);
  build(R[rt], mid + 1, r, mv, rv);
  push_up(rt);
}

// 替罪羊树
void rebuild(int &rt, double lv, double rv) {
  buffer_size = 0;
  flatten(rt);
  build(rt, 1, buffer_size, lv, rv);
}

void insert(int &rt, int p, double lv, double rv) {
  if (!rt) {
    new_node(rt, p, lv, rv);
    return;
  }

  if (cmp(p, rt))
    insert(L[rt], p, lv, tag[rt]);
  else
    insert(R[rt], p, tag[rt], rv);

  push_up(rt);
  if (!balance(rt))
    rebuild(rt, lv, rv);
}

void remove(int &rt, int p, double lv, double rv) {
  if (!rt)
    return;

  if (rt == p) {
    if (!L[rt] || !R[rt]) {
      rt = (L[rt] | R[rt]);
      rebuild(rt, lv, rv);
    } else {
      // 找到rt的前驱来替换rt
      int nrt = L[rt];
      while (R[nrt]) {
        nrt = R[nrt];
      }
      remove(L[rt], nrt, lv, tag[rt]);
      L[nrt] = L[rt];
      R[nrt] = R[rt];
      rt = nrt;
      tag[rt] = (lv + rv) / 2;
    }
  } else {
    double mv = (lv + rv) / 2;
    if (cmp(p, rt))
      remove(L[rt], p, lv, mv);
    else
      remove(R[rt], p, mv, rv);
  }

  push_up(rt);
  if (!balance(rt))
    rebuild(rt, lv, rv);
}

// s比t小 return true, s 比t大 return false, 相等返回 false
bool cmp1(char *s, int len, int p) {
  for (int i = 1; i <= len; ++i, --p) {// --p是因为s查询前被resverse了
    if (s[i] < t[p])
      return true;
    if (s[i] > t[p])
      return false;
  }
  return false;
}

int query(int rt, char *s, int len) {
  if (!rt)
    return 0;
  if (cmp1(s, len, rt))
    return query(L[rt], s, len);//s比t小进入左子树
  else
    return sz[L[rt]] + 1 + query(R[rt], s, len);//字符串在所有字串中的比较排名
}

void solve() {
  n = 0;
  scanf("%d", &q);
  init();

  scanf("%s", a + 1);
  na = strlen(a + 1);
  for (int i = 1; i <= na; ++i) {
    t[++n] = a[i];
    insert(root, n, 0, INF);
  }

  int mask = 0;
  char op[10];
  for (int i = 1; i <= q; ++i) {
    scanf("%s", op);

    // 三种情况分别处理

    if (op[0] == 'A') { // ADD
      scanf("%s", a + 1);
      na = strlen(a + 1);
      decode(a + 1, na, mask);

      for (int i = 1; i <= na; ++i) {
        t[++n] = a[i];
        insert(root, n, 0, INF);
      }
    } else if (op[0] == 'D') { // DEL
      int x;
      scanf("%d", &x);
      while (x) {
        remove(root, n, 0, INF);
        --n;
        --x;
      }
    } else if (op[0] == 'Q') { // QUERY
      scanf("%s", a + 1);
      na = strlen(a + 1);
      decode(a + 1, na, mask);

      reverse(a + 1, a + 1 + na);

      a[na + 1] = 'Z' + 1;//构造a的后继
      a[na + 2] = 0;
      int ans = query(root, a, na + 1);//a后继的排名

      --a[na];//构造a的前驱
      ans -= query(root, a, na + 1);//ans - a前驱的排名

      printf("%d\n", ans);
      mask ^= ans;
    }
  }
}

int main() {
  solve();
  return 0;
}