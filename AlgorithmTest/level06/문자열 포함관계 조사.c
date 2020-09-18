#include <stdio.h>
#include <string.h>

int main() {

  char A[1000];
  char B[1000];
  
  fgets(A,1000,stdin);
  fgets(B,1000,stdin);
  
  for(int i=0;i<strlen(A)-strlen(B);i++){
    int c = 0;
    
    for(int j=0;j<strlen(B);j++){
      if(A[i+j]==B[j]){
        c++;
      }
    }
    
    if(c==strlen(B)){
      printf("YES");
      return 0;
    }
  }
  
  printf("NO");
  return 0;
}
