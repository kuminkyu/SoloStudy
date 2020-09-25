
//모든 조합을 사용해서 푸는 "백트래킹을 활용한 완전 탐색 문제"
//+ - . 순으로 모든 조합을 계산해보기...
 
// . 처리 하는 것이 핵심! (연속되는 .이 나오면...?)
// 나머지는 그렇게 어렵지 않음..
// 시간복잡도는 3의 15승 안에 모든 것이 끝남.

#include <stdio.h>

int totalCount = 0;
        
            //현재위치,n값, sum값
void dessert(int x,int n,int sum,char temp[],int arr[],int ine[]){
                              //부호 배열,숫자 배열, 단순 부호 배열
  
  //기저조건
  if(x==n){
    
    //3  3
    int result = arr[0];
    //printf("\n%d ",result);
    //.이 연속되었는지 갯수 세어주는 totalCount
    
    int count = 0;
    int countSum = 0;
    int countTemp = 1;
    
    //43 + 45 - 46 .
    for(int i=0;i<n;i++){
      
      //printf("%d ",arr[i]);
      //printf("%c ",temp[i]);
      
      if(i==0 && temp[i]=='.'){
        result -= 1;
      }
      
      if(temp[i-1]=='.' && temp[i]!='.'){
        result += countSum;
        count = 0;
        countSum = 0;
      }
      
      if(temp[i] == '+' && temp[i+1]!='.'){
        result += arr[i+1];
      }
      else if(temp[i]=='-' && temp[i+1]!='.')
      {
        result -= arr[i+1];
      }
      
      else if(temp[i]=='.')
      {
        if(count == 0){
          
          if(i!=0 && temp[i-1]=='+'){
            countTemp = 1;
          }else if(temp[i-1]=='-'){
            countTemp = -1;
          }
          
          if(arr[i]>=9){
            countSum = (arr[i] * 100 + arr[i+1])*countTemp;
          }else{
            countSum = (arr[i] * 10 + arr[i+1])*countTemp;
          }
          
          count++;
          
        }else{
          if(arr[i]>=9){
            countSum = countSum * 100 + (arr[i+1]*countTemp);
          }else{
            countSum = countSum * 10 + (arr[i+1]*countTemp);
          }
          
          count++;
        }
        
        if(i==n-1){
          result += countSum;
        }
        
        if(count == n){
          result -= 1;
        }
      }
    }
    
    if(result==0){
      if(totalCount<20){
        for(int i=0;i<n;i++){
          printf("%d ",arr[i]);
          printf("%c ",temp[i]);
        }
        printf("%d\n",arr[n]);
      }
      totalCount++;
    }
    return;
    
    }else{
      for(int i=0;i<3;i++){
        temp[x] = ine[i];
        dessert(x+1,n,0,temp,arr,ine);
        }
      return;
    }
}

int main() {
  
  //입력크기 초기화
  int n;
  scanf("%d",&n);
  
  //현재까지의 값
  int sum =0;
  
  //입력 란에 따른 숫자 배열 초기화
  int arr[25];
  char temp[25];
  
  for(int i=0;i<n;i++){
    arr[i] = i+1;
  }
  
  //부호 배열 초초기화
  int ine[3];
  ine[0] = '+';
  ine[1] = '-';
  ine[2] = '.';
  
  dessert(0,n-1,0,temp,arr,ine);
  
  printf("%d",totalCount);
  
  return 0;
}


