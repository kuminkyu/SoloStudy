#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100005;

vector <int> graph[MAX];
vector <int> cost[MAX];

int table[MAX];
bool check[MAX];

vector <int> reverseGraph[MAX];
vector <int> reverseCost[MAX];

int reverseTable[MAX];
bool reverseCheck[MAX];

int n,m,k;

void inNode(int node){
  
  for(int i=0;i<=n;i++){
    table[i] = 987987987;
    check[i] = 0;
  }
  table[node] = 0;
}

void inNodeRe(int node){
  for(int i=0;i<=n;i++){
    reverseTable[i] = 987987987;
    reverseCheck[i] = 0;
  }
  reverseTable[node] = 0;
}

void distance(){
  //최소값 구함
  //최소값부터 뻗어나감
  
  for(int i=0;i<=n;i++){
    
    int minValue = 987987987; int minIndex = -1;
    
    for(int j=0;j<=n;j++){
      if(!check[j] && minValue > table[j]){
        minValue = table[j];
        minIndex = j;
      }
    }
    
    check[minIndex] = true;
    
    for(int j=0;j<graph[minIndex].size();j++){
      int node2 = graph[minIndex][j];
      int cost2 = cost[minIndex][j];
      
      if(table[node2] > table[minIndex] + cost2){
        table[node2] = table[minIndex] + cost2;
      }
    }
  }
}

void distanceRe(){
  //최소값 구함
  //최소값부터 뻗어나감
  
  for(int i=0;i<=n;i++){
    
    int minValue = 987987987; int minIndex = -1;
    
    for(int j=0;j<=n;j++){
      if(!reverseCheck[j] && minValue > reverseTable[j]){
        minValue = reverseTable[j];
        minIndex = j;
      }
    }
    
    reverseCheck[minIndex] = true;
    
    for(int j=0;j<reverseGraph[minIndex].size();j++){
      int node2 = reverseGraph[minIndex][j];
      int cost2 = reverseCost[minIndex][j];
      
      if(reverseTable[node2] > reverseTable[minIndex] + cost2){
        reverseTable[node2] = reverseTable[minIndex] + cost2;
      }
    }
  }
}

int main() {

  scanf("%d %d %d",&n,&m,&k);
  
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    
    graph[a].push_back(b);
    cost[a].push_back(c);
    
    reverseGraph[b].push_back(a);
    reverseCost[b].push_back(c);
  }
  
  int sum = 0;
  
  inNode(k);
  distance();
  
  for(int i=1;i<=n;i++){
    sum += table[i];
  }
  
  inNodeRe(k);
  distanceRe();
  
  for(int i=1;i<=n;i++){
    sum += reverseTable[i];
  }
  
  printf("%d\n",sum);
  
  return 0;
}
