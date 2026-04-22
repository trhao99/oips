#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,max_num = -1,min_num = 1001;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        if(t > max_num) max_num = t;
        if(t < min_num) min_num = t;
    }
    printf("%d",max_num - min_num);

    return 0;
}