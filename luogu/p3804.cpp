#include <bits/stdc++.h>

using namespace std;
struct state {
  int len, link; // link 指向该节点后缀树的父亲, len该等价组中最长字符串的长度
  // 字典树,该状态指向哪些字符(key)，那些字符的编号(value)
  std::map<char, int> next;
};
// const int MAXLEN = 1e6 + 2;
const int MAXLEN = 10;
state st[MAXLEN * 2];
int siz[MAXLEN * 2], t[MAXLEN * 2], A[MAXLEN * 2];

int sz, last;
long long ans;
void sam_init() {
  st[0].len = 0;
  st[0].link = -1;
  sz++;
  last = 0;
}
void sam_extend(char c) {
  int cur = sz++;
  siz[cur] = 1;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].next.count(c)) {
    st[p].next[c] = cur; // 维护字典树
    p = st[p].link;      // 后缀遍历
  }
  // 从后缀树上遍历，都遍历到根了，都没找到可以转移到c的状态(节点)
  if (p == -1) {
    st[cur].link = 0; // 后缀树直接指向空串代表的节点
  } else {
    int q = st[p].next[c];
    // 看他们是否存在父子关系，p,q字串同为以c为结尾的，若长度差1,则存在父子关系
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;              // 又新加一个节点
      st[clone].len = st[p].len + 1; // 复制p长度+1
      st[clone].next = st[q].next;   // 复制q 字典树指向
      st[clone].link = st[q].link;   // 复制q 后缀树指向
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
void solve() {
for (int i = 1; i <= sz; i++)
    t[st[i].len]++;//整个树所有等价集len长度出现频度统计。
  for (int i = 1; i <= sz; i++)
    t[i] += t[i - 1];//长度为i-1的字符串集合出现次数加到长度为i的字符串出现次数的统计中去。
  for (int i = 1; i <= sz; i++)
    A[t[st[i].len]--] = i;
  for (int i = sz; i >= 1; i--) {//dfs从后缀树叶子节点开始算每个等价集中的endpos数量
    int now = A[i];
    siz[st[now].link] += siz[now];
    if (siz[now] > 1)
      ans = max(ans, 1ll * siz[now] * st[now].len);
  }
}
int main() {
  // ifstream fin("P3804_1.in");
  char s[MAXLEN + 2];
  // fin >> (s+1);
  // fin.close();
  scanf("%s", s + 1);
  sam_init();
  for (int i = 1; s[i]; i++)
    sam_extend(s[i]);
  solve();
  cout << ans << endl;
  return 0;
}