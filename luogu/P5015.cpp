#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    string s;
    int res = 0;
    getline(cin, s);
    for(char c:s){
        if(c == ' ' || c == '\n') continue;
        res++;
    }
    printf("%d",res);
    return  0;
}