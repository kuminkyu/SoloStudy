#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10010;

vector <int> myGraph[MAX];
int color[MAX];
int check[MAX];

queue <int> q;
int n,m;
int flag = 0;

void BFS(){
  
  if(q.empty()) return;
  
  int current = q.front();
  int node_color = color[current];
  q.pop();
  
  check[current] = 1;
  
  for(int i = 0; i<myGraph[current].size();i++){
    int next = myGraph[current][i];
    
    if(color[next] == node_color){
      flag = -1;
      return;
    }
    
    if(check[next] == 0){
      q.push(next);
      check[next] = 1;
      color[next] = node_color*-1;
    }
  }
  
  if(!q.empty()) BFS();
}
int main(){
  
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  q.push(0);
  color[0] = 1;
  BFS();
  
  if(flag == 0){
    printf("YES");
  }else{
    printf("NO");
  }
}
