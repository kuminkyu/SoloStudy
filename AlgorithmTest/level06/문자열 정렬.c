#include <stdio.h>
#include <string.h>

int n;

char temp[110];
char str[100][100];

int main() {

  int n;
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%s",str[i]);
  }
  
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(strcmp(str[i],str[j])>0){
        
        strcpy(temp,str[j]);
        strcpy(str[j],str[i]);
        strcpy(str[i],temp);
      }
    }
  }
  
  for(int i=0;i<n;i++){
    printf("%s\n",str[i]);
  }
  return 0;
}
