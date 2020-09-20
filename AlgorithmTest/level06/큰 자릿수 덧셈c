#include <stdio.h>
#include <string.h>

char d[200],c[200];
char dd[200],cc[200];
char result[200];

int main(){
  
  scanf("%s %s",&d,&c);
  
  for(int i = 200-strlen(d);i<200;i++){
    dd[i] = d[strlen(d)-200+i]-'0';
  }
  
  for(int i = 200-strlen(c); i<200;i++){
    cc[i] = c[strlen(c)-200+i]-'0';
  }
  
  int max = strlen(d) > strlen(c) ? strlen(d) : strlen(c);
  
  for(int i = 199; i>=199-max; i--){
    result[i] += dd[i] + cc[i];
    if(result[i]>9){
      result[i-1]++;
      result[i] -= 10;
    }
  }
  
  for(int i = 199-max; i<=199; i++){
    if(result[i] == 0 && i == 199-max){
      continue;
    }
    else{
      printf("%d",result[i]);
    }
  }
  
  return 0;
}
