#include <stdio.h>

const int MAX = 100010;

int n;
int arr[MAX];

void mergeing(int arr[], int s1, int e1, int s2, int e2){
  
  int p,q;
  int temp[MAX];
  int temp_inx;
  
  p = s1;
  q = s2;
  
  while(p<=e1 && q<=e2){
    if(arr[p] < arr[q]){
      temp[temp_inx++] = arr[p];
      p++;
    }else{
      temp[temp_inx++] = arr[q];
      q++;
    }
  }
  
  if(p>e1){
    for(int i=q;i<=e2;i++){
      temp[temp_inx++] = arr[i];
    }
  }else{
    for(int i=p;i<=e1;i++){
      temp[temp_inx++] = arr[i];
    }
  }
  
  for(int i=s1;i<=e2;i++){
    arr[i] = temp[i-s1];
  }
}

void mergeSort(int arr[], int start, int end){
  
  if(start>=end){
    return;
  }
  
  int mid = (start+end)/2;
  
  mergeSort(arr,start,mid);
  mergeSort(arr,mid+1,end);
  
  mergeing(arr,start,mid,mid+1,end);
}

int main(){
  
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  mergeSort(arr,0,n-1);
  
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}


