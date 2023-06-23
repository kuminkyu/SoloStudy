#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1005;
int n;
int arr[MAX][MAX];
int map[MAX][MAX];
bool check[MAX][MAX];

int sum = 1;
int cnt = 0;

vector <int> v;

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

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void BFS(int y, int x){
    
    queue <p> Queue;
    
    Queue.push(make_p(y,x));
    cnt++;
    
    map[y][x] = 1;
    
    while(!Queue.empty()){
      
        p front = Queue.front();
        Queue.pop();
        
        int curY = front.y;
        int curX = front.x;
        
        for(int k = 0; k<4; k++){
            int yy = curY + dy[k];
            int xx = curX + dx[k];
            
            if(0<=yy && yy<=n && 0<=xx && xx<=n && map[yy][xx]==0 && check[yy][xx]){
                map[yy][xx] = 1;
                Queue.push(make_p(yy,xx));
                sum++;
            }
        }
    }
    
}

int main(){
    
    scanf("%d",&n);
    
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%1d",&arr[i][j]);
            if(arr[i][j]==1){
                check[i][j] = true;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j]==1 && map[i][j]==0){
                BFS(i,j);
                v.push_back(sum);
                sum = 1;
            }        
        }
    }
    
    sort(v.begin(),v.end());
    
    printf("%d\n",cnt);
    
    for(int i = 0;i<cnt;i++){
        printf("%d\n",v[i]);
    }
}
