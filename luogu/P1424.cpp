#include<bits/stdc++.h> 
using namespace std;
 
int main(){
    long long x,n,g=0;
    cin>>x>>n;
    for(int i=1;i<=n;i++){
		if(x!=6&&x!=7){
			g+=250;
		}
		x++;
		if(x>7) x=1;
	}
	cout<<g;
	return 0; 
} 
