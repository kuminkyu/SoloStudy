#include <stdio.h>


void bin(int x){
  
  if(x==1){
    printf("1");
  }
  else if(x==0){
    printf("0");
  }
  else{
    bin(x/2);
    printf("%d",x%2);
  }
}
int main(){
  int n;
  scanf("%d",&n);
  
  bin(n);
}
