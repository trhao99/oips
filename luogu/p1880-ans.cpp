#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int n,m,ans1,ans2;
int A[205],f1[205][205],f2[205][205];
int dfs1(int L,int R){                //求出最小得分
    if(f1[L][R])return f1[L][R];    //已保存的状态不必搜索
    if(L==R)    return f1[L][R]=0;    //L==R时返回0
    int res=INF;                    //初始值赋为最大值以求最小值
    for(int k=L;k<R;k++)            //枚举K搜索
        res=min(res,dfs1(L,k)+dfs1(k+1,R)+A[R]-A[L-1]);
    return f1[L][R]=res;            //记录状态
}
int dfs2(int L,int R){                //求出最大得分
    if(f2[L][R])return f2[L][R];
    if(L==R)    return f2[L][R]=0;    //若初始值为0可省略该句
    int res=0;                        //初始值设为0
    for(int k=L;k<R;k++)
        res=max(res,dfs2(L,k)+dfs2(k+1,R)+A[R]-A[L-1]);
    return f2[L][R]=res;
}
int main(){
    std::ios::sync_with_stdio(false);//取消cin与stdin同步,加速读入
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        A[i+n]=A[i];                //因为是环所以保存为长度为2n的链以保证不会漏解
    }
    for(int i=1;i<=2*n;i++)            //求出前缀和
        A[i]+=A[i-1];
    dfs1(1,2*n);dfs2(1,2*n);        //搜索出1-2n的最大得分与最小得分
    ans1=INF;    ans2=0;
    for(int i=1;i<=n;i++){
        ans1=min(f1[i][n+i-1],ans1);//选出答案
        ans2=max(f2[i][n+i-1],ans2);
    }
    cout<<ans1<<"\n"<<ans2;
    return 0;
}
