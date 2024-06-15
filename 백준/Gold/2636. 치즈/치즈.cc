#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M;
int board[105][105];
int last;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i  < N ; i++){
        for(int j = 0 ; j  < M ; j++){
            cin>>board[i][j];
        }
    }
}
bool check[105][105];
struct pos{
    int x;
    int y;
};
bool bfs(){
    memset(check,false,sizeof(check));
    int cnt = 0;
    pos c,n;
    c = {0,0};
    check[0][0] = true;
    queue<pos> q;
    q.push(c);
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > M-1 || check[n.x][n.y]) continue;
            
            if(board[n.x][n.y] == 1){
                board[n.x][n.y] = 0;
                cnt++;
            }
            else q.push(n);
            
            check[n.x][n.y] = true;
        }
    }
    if(cnt == 0) return false;
    else{
        last = cnt;
        return true;
    }

}
void result(){
    int cnt = 0;
    while(1){
        if(!bfs()) break;
        cnt++;
    }
    cout<<cnt<<"\n"<<last;
}

int main(void){
    input();
    result();
}