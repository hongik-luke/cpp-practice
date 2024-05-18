#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int IMF = 98765432;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int maxx,maxy;
int board[55][55];
bool visited[55][55];

void input(){
    cin>>maxx>>maxy;
    string n;
    for(int i = 0 ; i < maxx ; i++){
        cin>>n;
        for(int j = 0 ; j < maxy ; j++){
            if(n[j] == 'H')
                board[i][j] = 0;
            else
                board[i][j] = (int)n[j] - 48;
        }
    }
}
int cashe[55][55];
int dfs(int cx, int cy){
    if(visited[cx][cy]) return IMF;
    
    int& returnmax = cashe[cx][cy];
    if(returnmax != 0) return returnmax;
    returnmax = 1;
    visited[cx][cy] = true;
    for(int i = 0 ; i < 4 ; i++){
        int nx = cx + dx[i]*board[cx][cy];
        int ny = cy + dy[i]*board[cx][cy];
        if(nx < 0 || nx > maxx-1 || ny < 0 || ny > maxy-1 || board[nx][ny] == 0) continue;
        int result1 = 1+dfs(nx,ny);

        returnmax = max(returnmax,result1);
    }
    visited[cx][cy] = false;
    
    return returnmax;
}

int main(void){
    memset(visited,false,sizeof(visited));
    memset(cashe,0,sizeof(cashe));
    input();
    int result = dfs(0,0);
    if(result >= IMF) cout<<-1;
    else cout<<result;
}
