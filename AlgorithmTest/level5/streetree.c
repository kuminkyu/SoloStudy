#include <stdio.h>

int main(){
  
  int n;
  int arr[100010];
  int dis[100010];
  
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  for(int i=0;i<n-1;i++){
    dis[i] = arr[i+1]-arr[i];
  }
  
  /*for(int i=0;i<n-1;i++){
    printf("%d ",dis[i]);
  }*/
  
  int a,b,temp;
  
  b = dis[0];
  
  for(int i=0;i<n-2;i++){
    a = dis[i+1];
    
    while(a%b!=0){
      temp = a%b;
      a = b;
      b = temp;
    }
  }
  
  int t = 0;
  
  while(arr[0] + b*t<arr[n-1]){
    t++;
  }
  printf("%d",t-n+1);
  
  return 0; 
  
}
