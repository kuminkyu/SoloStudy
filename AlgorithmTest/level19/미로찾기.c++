#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1005;

int cost[MAX][MAX];
bool check[MAX][MAX];
int Map[MAX][MAX];

int n,m;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct p{
  int y;
  int x;
};

p make_p(int y,int x){
  p temp;
  temp.y = y;
  temp.x = x;
  return temp;
}

void getResult(int y, int x) {
    queue <p> Queue;

    Queue.push(make_p(y, x));
    check[y][x] = true;

    while(!Queue.empty()) {
    	p front = Queue.front();
    	Queue.pop();
    
    	int curY = front.y;
    	int curX = front.x;
    
    	for(int k=0;k<4;k++) {
    	    int yy = curY + dy[k];
    	    int xx = curX + dx[k];
    
    	    if(0 <= yy && yy < n && 0 <= xx && xx < m && 
    		    Map[yy][xx] == 0 && check[yy][xx]==0) {
          		check[yy][xx] = true;
          		cost[yy][xx] = cost[curY][curX] + 1;
          
          		Queue.push(make_p(yy, xx));
    	     }
      } 
    }
}
int main(){
  
  scanf("%d %d",&n, &m);

  for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++)
          scanf("%d",&Map[i][j]);
  }
  
  getResult(n-1, 0);
 
  printf("%d\n",cost[0][m-1]);
  
}
