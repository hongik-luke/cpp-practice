#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M;
int board[305][305];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
        }
    }
}
struct pos{
    int x;
    int y;
};
bool search_check[305][305];
void connect_bfs(int x,int y){
    queue<pos> q;
    pos c,n;
    c = {x,y};
    search_check[x][y] = true;
    q.push(c);
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            if(n.x < 0 || n.x > N-1  || n.y < 0 || n.y > M-1 || search_check[n.x][n.y] || board[n.x][n.y] == 0) continue;
            
            search_check[n.x][n.y] = true;
            q.push(n);
        }
    }
}
int connect(){
    memset(search_check,false,sizeof(search_check));
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i][j] != 0 && search_check[i][j] == false){
                connect_bfs(i,j);
                cnt++;
            }
        }
    }
    
    if(cnt == 0) return -1;
    else if(cnt == 1) return 0;
    else return 1;

}
bool check[305][305];
void bfs(int x,int y){
    queue<pos> q;
    pos c,n;
    c = {x,y};
    check[x][y] = true;
    q.push(c);
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            if(n.x < 0 || n.x > N-1  || n.y < 0 || n.y > M-1 || check[n.x][n.y]) continue;
            if(board[n.x][n.y] == 0){
                q.push(n);
                check[n.x][n.y] = true;
            }
            else{
                board[n.x][n.y]--;
                // 제일 중요한 코드 !!!!!!!
                if(board[n.x][n.y] == 0) check[n.x][n.y] = true;
            }
        }
    }
}
void all_bfs(){
    memset(check,false,sizeof(check));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i][j] == 0 && check[i][j] == false){
                bfs(i,j);
            }
        }
    }
}
int getresult(){
    int ret = 0;
    
    while(1){
        int n = connect();
        if(n == -1) return 0;
        if(n == 1) break;
        ret++;
        all_bfs();
    }
    return ret;
}
int main(void){
    input();
    cout<<getresult();
}