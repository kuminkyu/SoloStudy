#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 10005;

vector <int> myGraph[MAX];
int visited[MAX]={0,};

int n,m;
int flag = 0;

void DFS(int x,int color){
  
  visited[x] = color;
  
  for(int i=0;i<myGraph[x].size();i++){
    if(visited[myGraph[x][i]]==color){
      //printf("%d %d ",x,color);
      flag = 1;
      return;
    }
    if(visited[myGraph[x][i]]==0){
      DFS(myGraph[x][i],color*-1);
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
  
  DFS(0,1);
  
  if(flag == 1){
    printf("NO");
  }else{
    printf("YES");
  }
  
  return 0;
}
