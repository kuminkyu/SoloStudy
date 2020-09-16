#include <stdio.h>
int arr[40][40];
int main() {
  
  int c,r; //6,7
  scanf("%d %d",&c,&r);
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  
  int sum[40];
  int x,y;
  
  x = c;
  y = r;
  
  //작대기 둘 수 있는지 판단하는 코드
  int t=0;
  while(t<c){
    for(int i=0;i<r;i++){
      if(i==(r-1)){
        sum[t] = r-1;
        break;
      }
      if(arr[i][t]==1){
        sum[t] = i;
        break;
      }
    }
    t++;
  }
  
  int arg[40]={0};
  
  for(int j=0;j<c;j++){ //6
      //j번째 열 작대기 둘 수 있다면
      if(sum[j]>=4){
        int l;
        
        for(int i=0;i<r;i++){ //7
            if(i==r-1){
              l=i+1;
              break;
            }
            if(arr[i][j]==1){
              l=i;
              break;
            }
        }
        
        for(int i=l-1;i>l-5;i--){ //7
            if(arr[i][j]==0){
              arr[i][j] = 1;
            }
        }
        
        //몇 줄이 사라지는지 코드
        for(int i=l-1;i>l-5;i--){ //7
          int max = 0;
          for(int k=0;k<c;k++){
            if(arr[i][k]==1){
              max++;
            }
          }
          if(max==c){
            arg[j]++;
          }
        }
        
        //j번째 열에 뒀던 작대기 지우는 코드
        for(int i=l-1;i>l-5;i--){ //7
            if(arr[i][j]==1){
              arr[i][j] = 0;
            }
        }
      }
  }
 
  int maxj = 0;
  int maxi = 0;
  
  for(int j=0;j<c;j++){
    //printf("%d ",arg[j]);
    if(maxj<arg[j]){
      maxj = arg[j];
      maxi = j+1;
    }
  }
  
  printf("%d %d",maxi,maxj);
  
  return 0;
}


