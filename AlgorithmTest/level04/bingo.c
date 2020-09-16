#include <stdio.h>

int main(){
  
  int arr[5][5];
  
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  
  for(int k=1;k<=25;k++){
    
    int temp;
    
    scanf("%d",&temp);
    
    int cnt = 0;
    
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        if(arr[i][j] == temp){
          arr[i][j] = 0;
        }
      }
    }
    
    
    for(int t=0;t<5;t++){
      int sumi=0;
      int sumj=0;
      
      for(int tt=0;tt<5;tt++){
        sumj += arr[t][tt];
        sumi += arr[tt][t];
      }
      if(sumi == 0){cnt++;}
      if(sumj == 0){cnt++;}
    }
    
    int sumx=0,sumy=0;
    
    for(int t=0;t<5;t++){
      sumx += arr[t][t];
      sumy += arr[t][4-t];
    }
    if(sumx == 0) cnt++;
    if(sumy == 0) cnt++;
    
    if(cnt>=3){
      printf("%d",k);
      break;
    }  
  }
}
