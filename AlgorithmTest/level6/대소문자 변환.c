#include <stdio.h>
#include <string.h>

int main() {

  char str[1010];
  
  fgets(str,1010,stdin);
  
  for(int i=0;i<strlen(str);i++){
    if(str[i] >= 'a' && str[i] <= 'z'){
      str[i] = str[i] - 32;
    }
    else if(str[i] >= 'A' && str[i] <= 'Z'){
      str[i] = str[i] + 32;
    }
    else{
      str[i] = str[i];
    }
  }
  
  for(int i=0;i<strlen(str);i++){
    printf("%C",str[i]);
  }
  return 0;
}