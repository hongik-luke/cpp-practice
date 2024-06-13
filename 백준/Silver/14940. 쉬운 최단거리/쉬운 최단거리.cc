#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,M;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int board[1005][1005];
int check[1005][1005];
pair<int,int> f;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                f.first = i;
                f.second = j;
            }
        }
    }
}
struct pos{
    int x;
    int y;
    int value;
};
void bfs(){
    queue<pos> q;
    pos c,n;
    c = {f.first,f.second,0};
    q.push(c);
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(check[c.x][c.y] != -1) continue;
        check[c.x][c.y] = c.value;
        
        for(int i = 0 ; i < 4;  i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.value = c.value+1;
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > M-1 || board[n.x][n.y] == 0 ||check[n.x][n.y] != -1) continue;
            q.push(n);
        }
    }
}
int main(void){
    // 입력 및 초기화
    input();
    memset(check,-1,sizeof(check));
    // 결과 생성
    bfs();
    // 출력
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(check[i][j] == -1 && board[i][j] == 0) cout<<0<<" ";
            else cout<<check[i][j]<<" ";
        }
        cout<<"\n";
    }
}