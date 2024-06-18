#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int N,M;
int board[255][255];
bool check[255][255];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
        }
    }
}
void bfs(int x, int y){
    pair<int,int> c,n;
    c = make_pair(x,y);
    check[x][y] = true;
    queue<pair<int,int>> q;
    q.push(c);
    
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        for(int i = 0 ; i < 8 ; i++){
            n.first = c.first + dx[i];
            n.second = c.second + dy[i];
            
            if(n.first < 0 || n.first > N-1 || n.second < 0 || n.second > M-1 || check[n.first][n.second] || board[n.first][n.second] == 0) continue;
            q.push(n);
            check[n.first][n.second] = true;
        }
    }
}
int get(){
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i][j] == 1 && check[i][j] == false){
                bfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main(void){
    input();
    memset(check,false,sizeof(check));
    cout<<get();
}