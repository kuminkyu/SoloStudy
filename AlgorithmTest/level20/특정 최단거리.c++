//T[i]는 정점 i에 도달하는데 걸리는 최단거리
//(1) T[i]중 최솟값을 정한다. 단 지금까지 최솟값으로 뽑히지 않았던 값들 중
//(2) index로부터 뻗어나간다. T[index] + cost

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100005;

vector <int> graph[MAX];
vector <int> cost[MAX];

int Table[MAX];
bool check[MAX]; //check[i] = true 라면 i는 최단거리가 확정

int n,m;

void inNode(int node){
  //다익스트라 알고리즘
  for(int i=0;i<=n;i++){
    Table[i] = 987987987; //시작점 외 몰라서 값 초기화
    check[i] = 0;
  }
  Table[node] = 0;
}

void distance(){
  //1.최솟값을 구한다. 단 지금까지 최단거리로 확정되지 않았던 노드에 대해
  //2.그 최솟값을 갖는 노드로부터 뻗어나간다
    
  for(int i=0;i<=n;i++){
    
    int minValue = 987987987; int minIndex = -1;
    
    for(int j=1;j<=n;j++){
      if(!check[j] && minValue > Table[j]){
        minValue = Table[j];
        minIndex = j;
      }
    }
    
    check[minIndex] = true;
    
    for(int j=0;j<graph[minIndex].size();j++){
      int Node2 = graph[minIndex][j];
      int Cost2 = cost[minIndex][j];
      
      //minIndex -- (Cost2) -- Node2
      
      if(Table[Node2] > Table[minIndex] + Cost2){
        Table[Node2] = Table[minIndex] + Cost2;
      }
    }
  }
}

int main() {

  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    
    graph[a].push_back(b);
    graph[b].push_back(a);
    
    cost[a].push_back(c);
    cost[b].push_back(c);
  }
  
  int node1, node2;
  
  scanf("%d %d",&node1,&node2);
  
  inNode(1);
  distance();
  
  int sum = 0;
  int flag = 0;
  
  //node1과 node2 중에 작은값 계산
  if(Table[node1] > Table[node2]){
    sum += Table[node2];
    inNode(node2);
    flag = 1;
  }else{
    sum += Table[node1];
    inNode(node1);
  }
  distance();
  
  if(flag == 1){
    sum += Table[node1];
    inNode(node1);
  }else{
    sum += Table[node2];
    inNode(node2);
  }
  distance();
  
  sum += Table[n];
  
  printf("%d\n",sum);
  
  return 0;
}

/*
8 11 0 6
0 1 3
0 5 1
1 2 4
1 3 1
1 5 1
2 4 6
2 6 9
2 7 4
4 6 9
6 7 3
*/
