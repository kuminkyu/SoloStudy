#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100010;

int n,m;
vector <int> myGraph[MAX];
bool visited[MAX] ={0,};

void DFS(int x){
  
  visited[x] = true;
  printf("%d ",x);
  
  for(int i=0;i<myGraph[x].size();i++){
    int y = myGraph[x][i];
    
    if(visited[y]==false){
      DFS(y);
    }
  }
}

void BFS(int x){
  
  bool check[MAX] = {0,};
  queue <int> Queue;
  
  Queue.push(x);
  check[x] = true;
  
  while(!Queue.empty()){
    
    int current = Queue.front();
    printf("%d ",current);
    
    Queue.pop();
    for(int i=0;i<myGraph[current].size();i++){
      int next = myGraph[current][i];
      
      if(check[next] == false){
        check[next] = true;
        
        Queue.push(next);
      }
    }
  }
  
}

int main() {
  
  
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a,b;
    
    scanf("%d %d",&a,&b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  for(int i=0;i<m;i++){
    sort(myGraph[i].begin(),myGraph[i].end());
  }
  
  DFS(0);
  printf("\n");
  BFS(0);

  
  return 0;
}
