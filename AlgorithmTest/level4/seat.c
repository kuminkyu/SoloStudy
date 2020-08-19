#include <stdio.h>

int main(){
  
  int r,c,k;
  int arr[1005][1005];
  
  scanf("%d %d %d",&r,&c,&k);
  
  int temp = 0;
  int xtemp=1, ytemp= 0;
  
  int xcount = r-1;
  int ycount = c;
  
  while(temp<=r*c){
    
    for(int i = 0; i<ycount; i++){
      arr[++ytemp][xtemp] = ++temp;
      if(temp==k){
        printf("%d %d",xtemp,ytemp);
        return 0;
      }
    }
    ycount--;
    
    for(int i = 0; i<xcount; i++){
      arr[ytemp][++xtemp] = ++temp;
      if(temp==k){
        printf("%d %d",xtemp,ytemp);
        return 0;
      }
    }
    xcount--;
    
    for(int i = 0; i<ycount;i++){
      arr[--ytemp][xtemp] = ++temp;
      if(temp==k){
        printf("%d %d",xtemp,ytemp);
        return 0;
      }
    }
    ycount--;
    
    for(int i = 0; i<xcount; i++){
      arr[ytemp][--xtemp] = ++temp;
      if(temp==k){
        printf("%d %d",xtemp,ytemp);
        return 0;
      }
    }
    xcount--;
  }
  
  printf("0");
  return 0;
}