#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    int n,age,score;
    string name;
    cin >> n;
    for(int i = 0; i<n;i++){
       cin >> name >> age >> score; 
       printf("%s %d %d\n", name.c_str(), age+1, (int)min(600.0, score*1.2));
    }
    return 0;
}