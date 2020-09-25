#include <stdio.h>

int n;
int cnt = 0;
int arr[50];

void getResult(int x,int d){
  
  if(x>=n){
    cnt++;
    printf("%d",arr[0]);
    for(int i = 1; i<d; i++){
      printf("+%d",arr[i]);
    }
    printf("\n");
    return;
  }
  else{
    int num;
    
    if(x==0){
      num = n-1;
    }else{
      num = n-x;
    }
    
    for(int i = num; i>=1; i--){
      arr[d] = i;
      
      if(d>0 && arr[d-1] < arr[d]) continue;
      
      getResult(x+i,d+1);
    }
    
  }
}
int main(){
  
  scanf("%d",&n);
  
  getResult(0,0);
  printf("%d",cnt);
  
  return 0;
}
