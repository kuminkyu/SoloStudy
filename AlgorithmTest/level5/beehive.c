
#include <stdio.h>

int main() {

  //1     1번째방
  //2~7   2번째방
  //8~19
  
  int n;
  
  scanf("%d",&n);
  
  if(n==1){
    printf("1");
    return 0;
  }
  
  int a=1,b,r;
  
  int cnt=1;
  
  n -= 1;
  cnt++;
  
  while(1){
    
    n = n - a*6;
    if(n<=0){
      break;
    }
    cnt++;
    a++;
  }
  
  printf("%d",cnt);
  return 0;
}