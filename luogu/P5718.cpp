#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,c_m = 1000;
    cin >> n;
    for(int i = 0; i< n;i++){
        cin >> t;
        c_m = min(t, c_m);
    }
    printf("%d",c_m);
    return 0;
}