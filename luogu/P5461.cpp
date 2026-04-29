#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 1024 + 1;
bool persons[N][N]; // false说明不被赦免
void resolve(int x, int y, int len) {
  if (len == 2) {
    persons[x][y] = true;
    return;
  } else {
    for (int i = x; i < x + len / 2; i++) {
      for (int j = y; j < y + len / 2; j++) {
        persons[i][j] = true;
      }
    }
    resolve(x, y + len / 2, len / 2);
    resolve(x + len / 2, y, len / 2);
    resolve(x + len / 2, y + len / 2, len / 2);
  }
}
int main() {
  int n,len;
  cin >> n;
  len = pow(2, n);
  resolve(0, 0, len);
  for(int i = 0; i< len;i++){
    for(int j = 0; j < len;j++){
        if(persons[i][j]){
            printf("0 ");
        }else{
            printf("1 ");
        }
    }
    printf("\n");
  }
  return 0;
}