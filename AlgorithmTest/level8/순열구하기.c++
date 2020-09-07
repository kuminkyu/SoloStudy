#include <stdio.h>

const int MAX=105;

int n,r; //n이 i r이 j
char result[MAX];
bool check[MAX];

void getResult(int x){
  //x번째 for문을 돌려야 함
  
  //기저조건
  if(x>=r){
    printf("%s\n",result);
  }
  else{
    for(int i=0;i<n;i++){
      char alpha = i+'a';
      if(check[i] == false){
        
        result[x] = alpha;
        check[i] = true;
        
        getResult(x+1);
        
        //x번째에 i를 넣는 모든 경우를 이미 다 고려했음
        check[i] = false;
        result[x]=0;
      }
    }
  }
}

int main(){
  
  scanf("%d %d",&n,&r);
  
  getResult(0);
 
  return 0; 
}
