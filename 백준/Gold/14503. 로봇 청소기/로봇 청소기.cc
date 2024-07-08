#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N,M;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int board[52][52];
int robot_first[3];
void input(){
    cin>>N>>M;
    cin>>robot_first[0]>>robot_first[1]>>robot_first[2];
    for(int i =0 ; i < N; i++){
        for(int j =0 ; j < M; j++){
            cin>>board[i][j];
        }
    }
}
bool clean[52][52];
int ret = 0;
void simul(){
    int x = robot_first[0];
    int y = robot_first[1];
    int t = robot_first[2];
    while(1){
        if(!clean[x][y]){
            clean[x][y] = true;
            ret++;
        }
        bool flag = false;
        for(int i = 0 ; i < 4 ; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || board[nx][ny] == 1) continue;
            
            if(!clean[nx][ny]){
                flag = true;
                break;
            }
        }
        //청소할 곳이 있다.
        if(flag){
            t--;
            if(t == -1) t = 3;
            
            int nx = x + dx[t]; 
            int ny = y + dy[t];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || board[nx][ny] == 1 || clean[nx][ny]) continue;
            x = nx;
            y = ny;

        }
        //청소할 곳 없다.
        else{
            int nx = x + dx[(t+2)%4]; 
            int ny = y + dy[(t+2)%4];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || board[nx][ny] == 1) break;
            x = nx;
            y = ny;
        }

    }
}
int main(void) {
    FASTIO;
    input();
    memset(clean,false,sizeof(clean));
    simul();
    cout<<ret;
}