#include <stdio.h>
#include <string.h>

char d[200],c[200],cc[200],dd[200];
char result[200];

int main(){
  
  scanf("%s %s",&d,&c);
  
  for(int i = 200-strlen(d); i<200; i++){
    dd[i] = d[strlen(d)-200+i]-'0';
  }
  
  for(int i = 200-strlen(c); i<200; i++){
    cc[i] = c[strlen(c)-200+i]-'0';
  }
  
  int ii=0, judge;
  
  while(ii<200){
    if(dd[ii]>cc[ii]){
      judge=0;
      break;
    }
    if(cc[ii]>dd[ii]){
      judge=1;
      break;
    }
    ii++;
  }
  
  if(ii==200){
    printf("0"); 
    return 0;
  }
  
  for(int i = 199; i> 0; i--){
    if(judge==0){
      result[i] += dd[i]-cc[i];
    }
    if(judge==1){
      result[i] += cc[i]-dd[i];
    }
    
    if(result[i]<0){
      result[i]+=10;
      result[i-1]--;
    }
  }
  
  int t=0;
  while(result[t]==0){
    t++;
  }
  
  if(judge==1){
    printf("-");
  }
  
  for(int i=t;i<200;i++){
    printf("%d",result[i]);
  }
  
  return 0;
}
