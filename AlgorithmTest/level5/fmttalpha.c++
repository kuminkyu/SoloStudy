#include <iostream>

using namespace std;

int main(){
  
  int a,b;
  int n = 1;
  
  cin >> a >> b;
  
  int sum =0;
  
  while(sum<(b-a)){
    if(n%2==1){
      sum = (n/2+1) * (n/2+1);
      //printf("1. %d \n",sum);
    }
    if(n%2!=1){
      sum = ((n-1)/2+1) * ((n-1)/2+1) + n/2;
      //printf("2. %d \n",sum);
    }
    n++;
  }
  
  printf("%d",n-1);
}
