#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100005;
int check[MAX];
int arr[MAX];

int n;

typedef struct seq{
  
  int n;
  int m;
  seq(){};
  seq(int _n,int _m):n(_n),m(_m){};
}seq;

queue<seq>q;

void BFS(){
  if(q.empty()) return;
  seq now = q.front();
  q.pop();
  
  int a = now.n;
  int b = now.m;
  
  int numA = a*2;
  int numB = a/3;
  
  if(numA <= 99999 && check[numA] == 0){
    check[numA] = 1;
    arr[numA] = b+1;
    q.push(seq(numA,b+1));
  }
  
  if(numB >= 1 && check[numB]==0){
    check[numB] = 1;
    arr[numB] = b+1;
    q.push(seq(numB,b+1));
  }
  
  if(!q.empty()) BFS();
}

int main(){
  scanf("%d",&n);
  
  check[1] = 1;
  arr[1] = 0;
  q.push(seq(1,0));
  
  BFS();
  
  printf("%d",arr[n]);
}
