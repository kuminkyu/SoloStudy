#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100005;
const int MAX2 = 1005;

vector <int> List[MAX];
vector <int> reList[MAX];

int time2[MAX2], clock2=1;
int order[MAX2], order_cnt=0;
int group[MAX2], group_cnt=1;

bool check[MAX2],check2[MAX2];

int n,m;

void get_time(int node){
  
  check[node] = true;
  
  for(int i=0;i<List[node].size();i++){
    int node2 = List[node][i];
    
    if(!check[node2]){
      get_time(node2);
    }
  }
  
  time2[node] = clock2;
  clock2++;
  
  order[order_cnt++] = node;
}

void get_my_group(int node){
  
  check2[node] = true;
  group[node] = group_cnt;
  
  for(int i = 0; i<reList[node].size();i++){
    int node2 = reList[node][i];
    
    if(!check2[node2]){
      get_my_group(node2);
    }
  }
}

int main(){
  
  scanf("%d %d",&n,&m);
  
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    
    List[a].push_back(b);
    reList[b].push_back(a);
  }
  
  //노드마다 시간부여
  for(int i=1;i<=n;i++){
    if(!check[i]){
      get_time(i);
    }
  }
  
  //거꾸로 순회
  for(int i=order_cnt-1;i>=0;i--){
    int node = order[i];
    
    if(!check2[node]){
      get_my_group(node);
      group_cnt++;
    }
  }
  
  // for(int i = 1; i<=n;i++){
  //   printf("%d %d\n",i,group[i]);
  // }
  
  printf("%d",group_cnt-1);
}
