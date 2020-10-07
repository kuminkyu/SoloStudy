#include <stdio.h>

int getLeft(int arr[],int start, int end, int pivot, int result[]){
  //arr배열 start부터 end까지 pivot보다 작거나 같은값 result저장
  
  int inx=0;
  
  for(int i=start;i<=end;i++){
    if(arr[i]<=pivot){
      result[inx++] = arr[i];
    }
  }
  
  return inx;
}

int getRight(int arr[],int start, int end, int pivot, int result[]){
  //arr배열 start부터 end까지 pivot보다 큰수 rresult저장
  
  int inx = 0;
  
  for(int i=start;i<=end;i++){
    if(arr[i]>pivot){
      result[inx++] = arr[i];
    }
  }
  
  return inx;
}
void quickSort(int arr[],int start,int end){
  //arr배열 start부터 end까지 퀵 정렬
  
  //기저조건
  if(start>=end){
    return;
  }
  
  int left[100010],right[100010];
  int pivot = arr[start];
  
  int left_cnt = getLeft(arr,start+1,end,pivot,left);
  int right_cnt = getRight(arr,start+1,end,pivot,right);
  
  for(int i=0;i<left_cnt;i++){
    arr[start+i] = left[i];
  }
  
  arr[start+left_cnt] = pivot;
  
  for(int i=0;i<right_cnt;i++){
    arr[start+left_cnt+1+i] = right[i];
  }
  
  quickSort(arr,start,start+left_cnt-1);
  quickSort(arr,start+left_cnt+1,end);
  
}
int main(){
  
  int n;
  
  scanf("%d",&n);
  
  int arr[100010];
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  quickSort(arr,0,n-1);
  
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}
