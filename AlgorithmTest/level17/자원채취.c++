#include <iostream>

using namespace std;

const int MAX = 1010;

int main() {
  
  int n,m;
  int arr[MAX][MAX];
  int res[MAX][MAX];

  scanf("%d %d",&n,&m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  
  res[0][0] = arr[0][0];
  
  for(int i=1;i<n;i++) res[i][0] = res[i-1][0] + arr[i][0];
  for(int j=1;j<m;j++) res[0][j] = res[0][j-1] + arr[0][j];
  
  for(int i=1; i<n; i++){
    for(int j=1; j<m; j++){
      if(res[i-1][j] > res[i][j-1]){
        res[i][j] = arr[i][j]+res[i-1][j];
      }else{
        res[i][j] = arr[i][j]+res[i][j-1];
      }
    }
  }
  
  printf("%d",res[n-1][m-1]);
  
  return 0;
}
