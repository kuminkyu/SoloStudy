#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10010;
const int MAX2 = 1005;

vector <int> myGraph[MAX];
queue <int> q;

int color[MAX];
int check[MAX];

int flag = 0;
int n,m;

void BFS(){
  
  if(q.empty()) return;
  
  int current = q.front();
  int node_color = color[current];
  q.pop();
  
  for(int i= 0;i<myGraph[current].size();i++){
    int next = myGraph[current][i];
    
    if(color[next] == node_color){
      flag = -1;
      return;
    }
    
    if(check[next] == 0){
      
      q.push(next);
      check[next] = 1;
      color[next] = node_color * -1;
    }
  }
  
  if(!q.empty()) BFS();
}

int main(){
  
  scanf("%d %d",&n,&m);
  
  int a,b;
  
  for(int i=0;i<1;i++){
    scanf("%d %d",&a,&b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  int ta, tb;
  
  for(int i=1;i<m;i++){
    scanf("%d %d",&ta,&tb);
    
    myGraph[ta].push_back(tb);
    myGraph[tb].push_back(ta);
  }
  
  q.push(ta);
  color[ta] = 1;
  BFS();
  
  if(flag == 0){
    printf("Yes");
  }else{
    printf("No");
  }
}
