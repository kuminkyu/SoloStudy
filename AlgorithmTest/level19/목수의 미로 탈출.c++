#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1005;

int arr[MAX][MAX];
int check[MAX][MAX];
int n,m;

int checkR[MAX][MAX];

typedef struct coor{
  int n;
  int m;
  coor(){};
  coor(int _n,int _m):n(_n),m(_m){};
}coor;
queue <coor> q;

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

bool inside(int a,int b){
  return (a>=0 && a<n) && (b>=0&&b<m);
}

int flag = 0;
int cnt = 0;

void BFS(){
  if(q.empty()&&flag!=0) return;
  coor now = q.front();
  q.pop();
  
  int a,b;
  a = now.n;
  b = now.m;
  
  int temp = check[a][b];
  
  int nx,ny;
  for(int i=0;i<4;i++){
    nx = a+dx[i];
    ny = b+dy[i];
    if(inside(nx,ny)&&check[nx][ny]==0&&arr[nx][ny]!=1){
      now.n = nx;
      now.m = ny;
      q.push(now);
      check[nx][ny] = temp+1;
    }
  }
  if(!q.empty() && flag==0) BFS();
}

void BFS_R(){
  if(q.empty()&&flag!=0) return;
  coor now = q.front();
  q.pop();
  
  int a,b;
  a = now.n;
  b = now.m;
  
  int temp = checkR[a][b];
  
  int nx,ny;
  for(int i=0;i<4;i++){
    nx = a+dx[i];
    ny = b+dy[i];
    if(inside(nx,ny)&&checkR[nx][ny]==0&&arr[nx][ny]!=1){
      now.n = nx;
      now.m = ny;
      q.push(now);
      checkR[nx][ny] = temp+1;
    }
  }
  if(!q.empty() && flag==0) BFS_R();
}

int main(){
  
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  
  check[n-1][0] = 1;
  q.push(coor(n-1,0));
  BFS();
  
  checkR[0][m-1] = 1;
  q.push(coor(0,m-1));
  BFS_R();
  
  int min = 987987987;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      
      int sm=987987987,em=987987987;
      
      if(arr[i][j]==1){
        int nx, ny;
        
        for(int q=0;q<4;q++){
          nx = i+dx[q];
          ny = j+dy[q];
          
          if(inside(nx,ny)){
            if(sm>check[nx][ny] && check[nx][ny]!=0) sm = check[nx][ny];
            if(em>checkR[nx][ny] && checkR[nx][ny]!=0) em = checkR[nx][ny];
            if(min>sm+em) min = sm+em;
          }
        }
      }
    }
  }
  
  printf("%d",min);
  return 0;
}
