#include <stdio.h>

int d[100];
int num;
int length;

void printALL(int len){
  if(len!=num){
    return;
  }
  for(int i=0;i<length;i++){
    printf("%d",d[i]);
  }
  printf("\n");
}
void binaryFunc(int inx1,int len){
  if(len>num){
    return;
  }
  if(inx1==length){
    printALL(len);
    return;
  }
  
  d[inx1] = 1;
  binaryFunc(inx1+1,len+1);
  d[inx1] = 0;
  binaryFunc(inx1+1,len);
}
int main() {

  scanf("%d %d",&length,&num);
  
  binaryFunc(0,0);
  
  return 0;
}
