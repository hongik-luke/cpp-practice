#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N;
int board[22][22];
int eat_cnt = 0;
int shark_big = 2;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
        }
    }
}
struct pos{
    int x;
    int y;
    int value;
};
bool check[22][22];
int next_shark(){
    memset(check,false,sizeof(check));
    int sharkx,sharky;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == 9){
                sharkx = i;
                sharky = j;
                board[i][j] = 0;
                break;
            }
        }
    }

    pos c,n;    
    c = {sharkx,sharky,0};
    int distance = 9876543;
    queue<pos> q;
    queue<pos> resultq;
    q.push(c);
    
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(c.value >= distance){
            if(c.value == distance && board[c.x][c.y] != 0 && board[c.x][c.y] < shark_big) resultq.push(c);
            continue;
        }
        if(check[c.x][c.y]) continue;
        check[c.x][c.y] = true;
        if(board[c.x][c.y] != 0 && board[c.x][c.y] < shark_big){
            distance = c.value;
            resultq.push(c);
            continue;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.value = c.value+1;
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > N-1 || check[n.x][n.y] || board[n.x][n.y] > shark_big) continue;
            q.push(n);
        }
    }
    
    sharkx = 21; sharky = 21;
    while(!resultq.empty()){
        c = resultq.front();
        resultq.pop();
        if(c.x < sharkx){
            sharkx = c.x;
            sharky = c.y;
        }
        else if(c.x == sharkx){
            sharky = min(sharky, c.y);
        }
    }
    board[sharkx][sharky] = 9;
    
    if(distance == 9876543) return -1;
    else return distance;
}

int result(){
    int ret = 0;
    while(1){
        int n = next_shark();
        if(n == -1) break;
        else ret += n;
        eat_cnt++;
        if(eat_cnt == shark_big){
            shark_big++;
            eat_cnt = 0;
        }
    }
    return ret;
}
int main(void){
    input();
    cout<<result();
}