#include <stdio.h>
#include <string.h>

int main() {

  char arr[100];
  int len;
  int myStack[100],myTop=0;
  int sum=0;
  
  scanf("%s",arr);
  len = strlen(arr);
  
  for(int i=0;i<len;i++){
    // (((()())[][[]]))
    // -1-1-1 2 2 
    // 1.스택 맨위에 여는 괄호 
    //      맨위일 경우 여는 괄호 pop
    //      스택에 값을 push, () -> 2 [] ->3
    // 2.두번째 위 여는괄호 있을때 
    //      스택 맨위 있는 값, 두번째 위에 있는 여는 괄호 모두 pop
    //      스택에다 값을 push, (x) ->2x, [x] -> 3x
    // 3.둘다 값이면 합친다

    //            -1                -2
    if(arr[i] == '(' || arr[i] == '['){
      
      if(arr[i] == '(') myStack[myTop++] = -1;
      else myStack[myTop++] = -2;
    
    } //1.여는 괄호
    else{
      
      //스택이 비어있을 때
      if(myTop == 0){
        printf("0\n");
        return 0;
      }
      
      if(myStack[myTop-1]==-1 || myStack[myTop-1] == -2){
        if(arr[i] == ')' && myStack[myTop-1] == -1){
          myStack[--myTop] = 0;
          myStack[myTop++] = 2;
        }
        else if(arr[i] == ']' && myStack[myTop-1] == -2){
          myStack[--myTop] = 0;
          myStack[myTop++] = 3;
        }
        else{ // (] [)
          printf("0\n");
          return 0;
        }
        
        //2.값일 경우
      }else{
        //값을 빼주고 pop
        int myValue = myStack[myTop-1];
        myStack[myTop-1] = 0;
        myTop--;
        
        if(arr[i]==')' && myStack[myTop-1] == -1){
          myStack[--myTop] = 0;
          myStack[myTop++] = 2*myValue;
        }
        else if(arr[i] == ']' && myStack[myTop-1] == -2){
          myStack[--myTop] = 0;
          myStack[myTop++] = 3*myValue;
        }
        else{
          printf("0\n");
          return 0;
        }
        
        //2개 미만이면 안돌아감
        
      }
      if(myTop >= 2 && myStack[myTop-1] > 0 && myStack[myTop-2]>0){
          myStack[myTop-2] += myStack[myTop-1];
          myStack[--myTop] = 0;
      }
    }
  }
  
  if(myTop==1 && myStack[0]>0) printf("%d\n",myStack[0]);
  else printf("0\n");
  
  return 0;
}
