#include <stdio.h>

int n;
int d[250000];

int main(){
  
  for(int i=0;i<250000;i++){
    d[i] = 0;
  }
  
  for(int i=2;i<250000;i++){
    int sum =0;
    for(int j=1;j<=i;j++){
      if(i%j==0){
        sum++;
      }
    }
    if(sum==2){
      //printf("%d ",i);
      d[i]=1;
    }
  }
  
  /*for(int i=2;i<100;i++){
    printf("%d ",d[i]);
  }*/
 
  scanf("%d",&n);
  while(n!=0){
    
    int cnt =0;
    
    
    if(n==1){
      printf("1\n");
    }
    else
      {
      for(int i=n+1;i<=n*2;i++){
        if(d[i] == 1) cnt++;
      }
      
      printf("%d\n",cnt);
    }
    scanf("%d",&n);
  }
  
  return 0;
    
  
}
