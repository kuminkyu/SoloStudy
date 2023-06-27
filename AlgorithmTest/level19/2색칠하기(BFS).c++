#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10010;

int n,m;

vector <int> myGraph[MAX];
int check[MAX] ={0,};
int color[MAX] ={0,};
queue <int> q;

int flag = 0;
    
void BFS(){
  
  if(q.empty()) return;
  
  int current = q.front(); //0
  int node_color = color[current]; //1
  q.pop(); 
  
  check[current] = 1; //0
  
  for(int i=0;i<myGraph[current].size();i++){
      
      if(color[myGraph[current][i]] == node_color){
        //printf("%d ",myGraph[current][i]);
        flag =-1;
        return;
      }
      
      //printf("%d ",myGraph[current][i]);
      
      if(check[myGraph[current][i]]==0){
        q.push(myGraph[current][i]);
        check[myGraph[current][i]]=1;
        color[myGraph[current][i]]=node_color*-1;
      }
  }
  
  if(!q.empty()){
    BFS();
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
  
  q.push(0);
  color[0] = 1;
  BFS();
  
  if(flag == 0){
    printf("YES");
  }else{
    printf("NO");
  }
  
  return 0;
}
