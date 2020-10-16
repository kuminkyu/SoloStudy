#include <stdio.h>

int main() {

  int Stack[100], myTop=0;
  
  int n,m;
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a;
    scanf("%d",&a);
    
    if(a==1){
      int b;
      
      scanf("%d",&b);
      
      if(myTop>=n){
        printf("Overflow\n");
      }
      else{
        Stack[myTop++] = b;
      }
    }
    else if(a==2){
      if(myTop==0){
        printf("Underflow\n");
      }
      else{
        Stack[myTop--] = 0;
      }
    }
    else{
      if(myTop==0){
        printf("NULL\n");
      }
      else{
        printf("%d\n",Stack[myTop-1]);
      }
    }
  }
  
  return 0;
}


