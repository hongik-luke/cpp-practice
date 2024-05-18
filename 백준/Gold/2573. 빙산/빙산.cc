#include <iostream>
#include <algorithm>
#include <cstring>

#include <vector>
#include <queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct pos{
    int x;
    int y;
};

int maxx,maxy;
int board[305][305];

void input(){
    cin>>maxx>>maxy;
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            cin>>board[i][j];
}

bool visited[305][305];
void bfs(int fx, int fy){
    pos npos,cpos;
    cpos = {fx,fy};
    queue <pos> q;
    q.push(cpos);
    visited[cpos.x][cpos.y] = true;
    
    while(!q.empty()){
        cpos = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            npos.x = cpos.x + dx[i];
            npos.y = cpos.y + dy[i];
            
            if(npos.x < 0 || npos.x > maxx-1 || npos.y < 0 || npos.y > maxy-1 || visited[npos.x][npos.y]) continue;
            
            if(board[npos.x][npos.y] > 0){
                q.push(npos);
                visited[npos.x][npos.y] = true;
            }
            else{
                if(board[cpos.x][cpos.y] > 0)
                    board[cpos.x][cpos.y]--;
            }
        }
    }
    
    return;
    
    
    
}

int getresult(){
    int returnresult = 0;
    while(1){
        int cnt = 0;
        memset(visited,false,sizeof(visited));
        for(int i = 0 ; i < maxx ; i++){
            for(int j = 0 ; j < maxy ; j++){
                if(board[i][j] > 0 && !visited[i][j]){
                    cnt++;
                    bfs(i,j);
                }
            }
        }

        if(cnt == 0) return 0;
        if(cnt >= 2) return returnresult;
        
        cnt = 0;
        returnresult++;
            
    }
}

int main(void){
    input();
    cout<<getresult()<<"\n";
}