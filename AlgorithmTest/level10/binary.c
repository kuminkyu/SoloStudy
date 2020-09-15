#include <stdio.h>

int binarySearch(int arr[], int start, int end, int value){
  //start부터 end중에 value 값이 있다면 위치반환
  //없다면 -1 위치 반환
  
  //기저조건
  if(start>end){
    return -1;
  }else if(start==end){
    if(arr[start] == value) return start;
    else return -1;
  }else{
    int mid = (start+end)/2;
    
    if(arr[mid] < value) binarySearch(arr,mid+1,end,value);
    else if(arr[mid] > value) binarySearch(arr,start,mid-1,value);
    else{
      if(arr[mid]==value) return mid;
      else return -1;
    }
  }
}

int main(){
  
  int n,m;
  scanf("%d %d",&n,&m);
  
  int arr[100010];
  int arr2[100010];
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  for(int i=0;i<m;i++){
    scanf("%d",&arr2[i]);
    int inx = binarySearch(arr,0,n-1,arr2[i]);
  
    if(inx == -1){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
  }
  
  
  return 0;
}
