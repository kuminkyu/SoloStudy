#include <stdio.h>

int main(){
  
  int n;
  scanf("%d",&n);
  
  int information[105][3]; //[0]은 숫자 [1]은 스트라이크 [2]은 볼
  
  for(int i=0;i<n;i++){
    scanf("%d %d %d",&information[i][0],&information[i][1],&information[i][2]);
  }
  
  int result = 0;
  
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      for(int k=1;k<=9;k++){
        
        if(i!=j && j!=k && k!=i){
          
          bool flag = false;
          
          for(int p=0;p<n;p++){
            
            int strike=0,ball=0;
            
            int first = information[p][0]/100;
            int second = (information[p][0]/10)%10;
            int third = information[p][0]%10;
            
            if(first == i){strike++;}
            if(second == j){strike++;}
            if(third == k){strike++;}
            
            if(i == second || i == third){ball++;}
            if(j == first || j == third){ball++;}
            if(k == first || k == second){ball++;}
            
            if(information[p][1] != strike || information[p][2] != ball){
              flag = true;
            }
          }
          
          if(flag == false){
            //printf("%d %d %d\n",i,j,k);
            result++;
          }
        }
      }
    }
  }
  printf("%d",result);
  return 0;
  
}
