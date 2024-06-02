#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int N,M;
char board[105][105];
bool visited[105][105][4];
pair<int,int> razer[2];
void input(){
    cin>>M>>N;
    char n;
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
            if(board[i][j] == 'C'){
                board[i][j] = '.';
                razer[cnt++] = make_pair(i,j);
            }
        }
    }
}
struct pos{
    int x;
    int y;
    int type;
    int value;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }
};

int get(){
    pos c,n;
    priority_queue<pos,vector<pos>,cmp> pq;
    for(int i = 0 ; i < 4 ; i++){
        c = {razer[0].first, razer[0].second,i, 0};
        pq.push(c);
    }
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        if(c.x == razer[1].first && c.y == razer[1].second)
            return c.value;
        
        if(visited[c.x][c.y][c.type]) continue;
        visited[c.x][c.y][c.type] = true;

        for(int i = 0 ; i < 4 ; i++){
            if(c.type == (i+2)%4) continue;
            n = {c.x+dx[i], c.y+dy[i] ,i, c.value};
            if(n.type != c.type) n.value = c.value+1;
            
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > M-1 || visited[n.x][n.y][n.type]) continue;
            if(board[n.x][n.y] == '*') continue;
            pq.push(n);
        }
        
    }

}

int main(void){
    input();
    memset(visited,false,sizeof(visited));
    cout<<get();
}