#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000005;
const int nMAX = 10005;

vector <int> graph[MAX];
int arr[nMAX] = {0,};

queue <int> q;

int n,m;

void BFS(){
  
  if(q.empty()) return;
  
  int node = q.front();
  q.pop();
  
  for(int i = 0;i <graph[node].size();i++){
    if(arr[graph[node][i]] == 0){
      q.push(graph[node][i]);
      arr[graph[node][i]] = arr[node] + 1;
    }
  }
  
  if(!q.empty()) BFS();
  
}

int main() {
  
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a,b;
    
    scanf("%d %d",&a,&b);
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  int start,end2;
  scanf("%d %d",&start,&end2);
  
  q.push(start);
  arr[start] = 0;
  
  BFS();
  
  printf("%d",arr[end2]);
  
  return 0;
}
