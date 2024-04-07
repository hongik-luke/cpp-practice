#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

struct pos{
    int x;
    int y;
};

int Map[1001][1001];
int n,m,k;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS(pos start, pos finish){
    pos nowidx, newidx;
    queue <pos> pq;
    pq.push(start);

    if(finish.x == nowidx.x && finish.y == nowidx.y)
        return 1;
    
    while(!pq.empty()){
        nowidx = pq.front();
        pq.pop();
        for(int i = 0 ; i < 4 ; i++){
            newidx.x = nowidx.x;
            newidx.y = nowidx.y;
            for(int j = 1 ; j <= k ; j++){
                newidx.x += dx[i];
                newidx.y += dy[i];
                
                if(newidx.x < 0 || newidx.x > n-1 || newidx.y < 0 || newidx.y > m-1|| Map[newidx.x][newidx.y] == -1)
                    break;
                if(Map[newidx.x][newidx.y] != 0 && Map[newidx.x][newidx.y] <= Map[nowidx.x][nowidx.y])
                    break;
                if(Map[newidx.x][newidx.y] == 0){
                    pq.push(newidx);
                    Map[newidx.x][newidx.y] = Map[nowidx.x][nowidx.y] +1;
                    if(finish.x == newidx.x && finish.y == newidx.y)
                        return 1;
                }
            }
        }
    }
    return 0 ;
}

int main(void){
    cin>>n>>m>>k;
    char now;
    pos start,finish;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>now;
            if(now == '.') Map[i][j] = 0;
            else Map[i][j] = -1;

        }
    }
    cin>>start.x>>start.y>>finish.x>>finish.y;  
    start.x-=1;start.y-=1;finish.x-=1;finish.y-=1;
     
    if(BFS(start,finish) == 1) cout<<Map[finish.x][finish.y]<<"\n";
    else cout<<-1<<"\n";
}
            