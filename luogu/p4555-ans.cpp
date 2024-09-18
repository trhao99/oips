#include <bits/stdc++.h>
#define ll long long
#define space putchar(' ')
#define endl putchar('\n')
#define debug puts("------------------------")
using namespace std;
inline void read(int &a) {a = 0; int c = getchar(), b = 1; while (c > '9' || c < '0') {if (c == '-')b = -1; c = getchar();} while (c >= '0' && c <= '9') a = (a << 3) + (a << 1) + c - 48, c = getchar(); a *= b; }
inline int  Rem() {int a = 0, c = getchar(), b = 1; while (c > '9' || c < '0') {if (c == '-')b = -1; c = getchar();} while (c >= '0' && c <= '9') a = (a << 3) + (a << 1) + c - 48, c = getchar(); return a *= b; }
inline void write(int x) {if (x > 9)write(x / 10); putchar('0' + x % 10);}
inline void W(int x) {if (x < 0) {putchar('-'), x = -x;} write(x);}
/**/
const int N = 11000005;
char a[N], s[N << 1];
int n, hw[N << 1], ans, l[N << 1], r[N << 1];
/**/
void Pre()//非常模板的插入
{
	s[0] = '#';
	s[1] = '$';
	int cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		s[++cnt] = a[i];
		s[++cnt] = '$';
	}
	n = (n << 1) + 2;
	s[n] = '~';
}

void work()//同样非常模板的Manacher
{
	int mr = 0, mid;
	for (int i = 1; i <= n; i++)
	{
		if (i < mr) hw[i] = min(hw[(mid << 1) - i], mr - i);
		else hw[i] = 1;
		while (s[i + hw[i]] == s[i - hw[i]]) ++hw[i];
		if (hw[i] + i > mr) mr = hw[i] + i, mid = i;
		/**
		 * l[i]表示以i为左端点的最长的回文串
		 * r[i]表示以i为右端点的最长的回文串
		 *
		 * 对于蒟蒻(我)来讲有点抽象所以我们举一个生动的栗子：
		 *
		 * 		首先，字符串为ababaccd
		 *
		 * 				  0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17
		 * 		插入后变成 #|$|a|$|b|$|a|$|b|$|a |$ |c |$ |c |$ |d |~
		 *
		 * 		显然i = 4时,hw[4] = 4
		 * 		L = 7 = i + hw[4]-1;
		 * 		R = 1 = i-hw[4]+1;
		 * 		回文串实际长度=hw[4]-1;
		 * 		所以转移就是: l[i+hw[i]-1]=max(l[i+hw[i]-1],hw[i]-1);
		 * 					 r[i-hw[i]+1]=max(r[i-hw[i]+1],hw[i]-1);
		 *
		 */
		r[i + hw[i] - 1] = max(r[i + hw[i] - 1], hw[i] - 1);
		l[i - hw[i] + 1] = max(l[i - hw[i] + 1], hw[i] - 1);
	}
}

int main()
{
	scanf("%s", a + 1);
	n = strlen(a + 1);
	Pre();
	work();
/**
 *	又因为两块不能重叠，所以我们选择'$'作为断点进行枚举
 *
 *  那么先提出一个困扰蒟蒻我的问题：
 * 
 *	Q: 上面不是已经求过了吗，为什么还要递推呢？
 *
 *  A: 上面求出的每个l[i]和r[i]都是在i最大的情况下求的
 *  	
 *  	eg:0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17
 *		   #|$|a|$|b|$|a|$|b|$|a |$ |c |$ |c |$ |d |~
 *
 * 		l[3]求出来的是0,但很明显bab是一个回文,l[3]应该等于3
 * 		这是因为我们在i=6时,hw[i]=6,只更新了l[1]和r[11],因为bab不是i=6的最长回文串所以没有更新
 *
 * 		这时就需要递推把前面的转移过来了：
 *
 * 			bab 比 ababa 短两个字符。
 * 			每一个回文串向后挪动一个 都会少两个字符,所以：
 * 		 	l[i] = max(l[i], l[i - 2] - 2);
 * 			r[i] = max(r[i], r[i + 2] - 2);
 * 			我们枚举的是'$'的位置，所以l[i]正推由前一个'$'的位置转移来,r[i]逆推由后面的'$'转移来，每次都会-2回文串长度
 *
 */
	for (int i = n; i >= 1; i -= 2) r[i] = max(r[i], r[i + 2] - 2);
	for (int i = 1; i <= n; i += 2) l[i] = max(l[i], l[i - 2] - 2);

	for (int i = 1; i <= n; i += 2) if (r[i] && l[i]) ans = max(ans, l[i] + r[i]);
	W(ans);
	return 0;
}