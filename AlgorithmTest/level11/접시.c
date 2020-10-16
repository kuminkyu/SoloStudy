#include <stdio.h>
#include <string.h>

int main() {
  
  int result[60],resultlen=0;
  
  bool flag = false;
  char data[30];
  int len;
  int cursor = 0;
  
  char myStack[30], myTop=0;
  char curAlpha = 'a';
  
  scanf("%s",data);
  len = strlen(data);
  
  while(1){
    
    char topElement;
    
    if(myTop==0) topElement = 0;
    else topElement = myStack[myTop-1];
    
    char currentElement = data[cursor];
    
    if(topElement == currentElement){
      myStack[myTop-1] = 0;
      myTop--;
      
      result[resultlen] = 0;
      resultlen++;
      
      cursor++;
      
      if(cursor>=len){
        flag = true;
        break;
      }
    }else{
      if(curAlpha >= 'a'+len){
        flag = false;
        break;
      }
      myStack[myTop] = curAlpha;
      myTop++;
      
      result[resultlen] = 1;
      resultlen++;
      
      curAlpha++;
    }
    
  }
  if(flag==true){
    for(int i = 0; i<resultlen; i++){
      if(result[i] == 0){
        printf("pop\n");
      }else{
        printf("push\n");
      }
    }
  }else{
      printf("impossible\n");
  }
  return 0;
}


