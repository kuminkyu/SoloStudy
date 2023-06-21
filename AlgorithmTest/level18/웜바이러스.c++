#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 105;
int n,m;

vector <int> myGraph[MAX];
queue <int> q;

int check[MAX];
int sum = 0;

void BFS(){
  
  if(q.empty()) return;
  
  int current = q.front();
  
  check[current] = 1;
  q.pop();
  sum++;
  
  for(int i = 0;i<myGraph[current].size();i++){
    int next = myGraph[current][i];
    
    if(check[next] == 0){
      q.push(next);
      check[next] = 1;
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
  
  q.push(1);
  BFS();
  
  printf("%d",sum-1);
  
}
