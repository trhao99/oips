#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const long long INF = 1e18;
const int N = 8e5 + 10;
struct treap {
  long long val;
  int lson, rson;
  int size;
  int cnt;
  int key;
};
treap trp[N];
char s[N], ty[11], str[N];
int root;
void decode(char *ch, int mask) {
  int l = strlen(ch);
  for (int i = 0; i < l; i++) {
    mask = (mask * 131 + i) % l;
    char t = ch[i];
    ch[i] = ch[mask];
    ch[mask] = t;
  }
}
inline int comp(int x, int y) {
  if (s[x] > s[y] || s[x] == s[y] && trp[x - 1].val > trp[y - 1].val)
    return 1;
  else if (s[x] == s[y] && trp[x - 1].val == trp[y - 1].val)
    return 0;
  else
    return -1;
}
inline bool check(int pos) {
  for (int i = 1, j = pos; str[i]; i++, j--)
    if (str[i] < s[j])
      return true;
    else if (str[i] > s[j])
      return false;
  return false;
}

inline void pushup(int pos) {
  int lson = trp[pos].lson, rson = trp[pos].rson;
  trp[pos].size = trp[lson].size + trp[rson].size + trp[pos].cnt;
}
void dfs(int pos, long long l, long long r) {
  int lson = trp[pos].lson, rson = trp[pos].rson;
  trp[pos].val = (l + r) >> 1;
  if (lson)
    dfs(lson, l, trp[pos].val - 1);
  if (rson)
    dfs(rson, trp[pos].val + 1, r);
}
void zig(int &p, long long l, long long r) {
  int q = trp[p].lson;
  trp[p].lson = trp[q].rson;
  trp[q].rson = p;
  pushup(p);
  pushup(q);
  dfs(q, l, r);
  p = q;
}
void zag(int &p, long long l, long long r) {
  int q = trp[p].rson;
  trp[p].rson = trp[q].lson;
  trp[q].lson = p;
  pushup(p);
  pushup(q);
  dfs(q, l, r);
  p = q;
}
int merge(int x, int y) {
  if (!x || !y)
    return x + y;
  if (trp[x].key < trp[y].key) {
    trp[x].rson = merge(trp[x].rson, y);
    pushup(x);
    return x;
  } else {
    trp[y].lson = merge(x, trp[y].lson);
    pushup(y);
    return y;
  }
}
void ins(int &now, int pos, long long l, long long r) {
  if (!now) {
    trp[pos].lson = trp[pos].rson = 0;
    trp[pos].key = rand();
    trp[pos].val = (l + r) / 2;
    trp[pos].size = 1;
    trp[pos].cnt = 1;
    now = pos;
    return;
  }
  if (comp(now, pos) > 0) {
    ins(trp[now].lson, pos, l, trp[now].val - 1);
    pushup(now);
    if (trp[now].key > trp[trp[now].lson].key)
      zig(now, l, r);
  } else if (comp(now, pos) < 0) {
    ins(trp[now].rson, pos, trp[now].val + 1, r);
    pushup(now);
    if (trp[now].key > trp[trp[now].rson].key)
      zag(now, l, r);
  } else {
    trp[now].cnt++;
    pushup(now);
  }
}
void del(int &now, int pos, long long l, long long r) {
  if (!now)
    return;
  if (comp(now, pos) == 0) {
    if (trp[now].cnt > 1)
      trp[now].cnt--;
    else {
      now = merge(trp[now].lson, trp[now].rson);
      if (now)
        dfs(now, l, r);
    }
    return;
  }
  if (comp(now, pos) > 0)
    del(trp[now].lson, pos, l, trp[now].val - 1);
  else
    del(trp[now].rson, pos, trp[now].val + 1, r);
  pushup(now);
}
int rnk(int now) {
  if (!now)
    return 1;
  else if (check(now))
    return rnk(trp[now].lson);
  else
    return rnk(trp[now].rson) + trp[trp[now].lson].size + trp[now].cnt;
}
int main() {
  int n;
  cin >> n;
  cin >> (s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++)
    ins(root, i, 1, INF);
  int l, x;
  int ans;
  int mask = 0;
  while (n--) {
    cin >> (ty + 1);
    switch (ty[1]) {
    case 'A':
      cin >> (str + 1);
      decode(str + 1, mask);
      l = strlen(str + 1);
      for (int i = len + 1; i <= len + l; i++) {
        s[i] = str[i - len];
        ins(root, i, 1, INF);
      }
      len += l;
      break;
    case 'D':
      cin >> x;
      for (int i = len; i > len - x; i--)
        del(root, i, 1, INF);
      len -= x;
      break;
    case 'Q':
      cin >> (str + 1);
      decode(str + 1, mask);
      int l = strlen(str + 1);
      reverse(str + 1, str + l + 1);
      str[l + 1] = 'Z' + 1;
      str[l + 2] = '\0';
      ans = rnk(root);
      str[l]--;
      ans -= rnk(root);
      mask ^= ans;
      cout << ans << '\n';
      break;
    }
  }
}