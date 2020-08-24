#include <stdio.h>
#include <string.h>

char c[500],d[500];
int cc[500],dd[500];
int result[500];

int main(){
  
  scanf("%s %s",&d,&c);
  
  for(int i = 500-strlen(d); i<500; i++){
    dd[i] = d[strlen(d)-500+i] - '0';
  }
  
  for(int i = 500-strlen(c); i<500; i++){
    cc[i] = c[strlen(c)-500+i] - '0';
  }
  
  for(int i = 499; i>strlen(d); i--){
    
    int k = 499;
    int t = 0;
    
    for(int j = 0; j<strlen(c); j++){
      result[i-t] += dd[i]*cc[k];
      
      if(result[i] > 9){
        result[i-1-t] += result[i-t]/10;
        result[i-t] = result[i-t]%10;
      }
      
      k--; t++;
    }
  }
  
  int n = 0;
  
  while(result[n]==0){
    n++;
  }
  
  for(int i = n; i<500;i++){
    printf("%d",result[i]);
  }
}
