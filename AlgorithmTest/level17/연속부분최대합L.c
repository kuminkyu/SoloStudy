#include <stdio.h>

const int MAX = 1000010;
int arr[MAX];
int Table[MAX];
int n;

int main() {
  
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  Table[0] = arr[0];
  
  for(int i=1;i<n;i++){
    if(Table[i-1]+arr[i] > arr[i]) Table[i] = Table[i-1]+arr[i];
    else Table[i] = arr[i];
  }
  
  int myMax = -987987987;
  
  for(int i=0;i<n;i++){
    if(myMax<Table[i]){
      myMax = Table[i];
    }
  }
  
  printf("%d",myMax);
  
  return 0;
}
