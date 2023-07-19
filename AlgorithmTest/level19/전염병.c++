#include <stdio.h>

int main() {
  bool check[100050];
  int myQueue[100050];
  int front=0,rear=0;
  int n,k;
  
  scanf("%d %d",&n,&k);
  
  check[k] = true;
  myQueue[rear++]=k;

  while(front < rear){
    int current = myQueue[front++];
    
    if(current*2 <=n && check[current*2] == false){
      check[current*2] = true;
      myQueue[rear++] = current*2;
    }
    
    if(current/3 >=1 && check[current/3]==false){
      check[current/3] = true;
      myQueue[rear++] = current/3;
    }
  }
  
  int cnt = 0;
  for(int i=1;i<=n;i++){
    if(check[i] == false){
      cnt++;
    }
  }
  
  printf("%d",cnt);
  return 0;
}
