#include <stdio.h>

void mountain(int n){
  
  if(n==1){
    printf("1");
  }else{
    mountain(n-1);
    printf("%d",n);
    mountain(n-1);
  }
}
int main(){
  
  int n;
  scanf("%d",&n);
  
  mountain(n);
  
}
