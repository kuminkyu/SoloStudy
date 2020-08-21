#include <stdio.h>

int pascal(int a,int b){
  
  int t;
  if(b==0) return 1;
  if(a==b) return 1;
  t = pascal(a-1,b-1)+pascal(a-1,b);
  
  return t;
}
int main(){
  
  int n,m;
  
  scanf("%d %d",&n,&m);
  
  printf("%d",pascal(n,m));
  return 0;
  
}
