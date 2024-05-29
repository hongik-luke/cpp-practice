#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N,M;
int dirty_cnt;
pair<int,int> dirty[12];
pair<int,int> f;
char board[22][22];
bool input(){
    dirty_cnt = 0;
    cin>>M>>N;
    if(N == 0 && M == 0) return true;
    char n;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>n;
            if(n == 'o'){
                f = {i,j};
                board[i][j] = '.';
                continue;
            }
            else if(n == '*'){
                dirty[dirty_cnt++] = {i,j};
            }
            
            board[i][j] = n;
        }
    }

    return false;
}
int cashe[22][22][(1<<10)];
struct pos{
    int x;
    int y;
    int value;
};
bool visited[22][22];
bool bfs(int fx, int fy, int how_far[]){
    memset(visited,false,sizeof(visited));
    pos c,n;
    c = {fx,fy,0};
    queue <pos> pq;
    pq.push(c);
    
    while(!pq.empty()){
        c = pq.front();
        pq.pop();
        //cout<<c.x<<" "<<c.y<<"\n";
        if(visited[c.x][c.y]) continue;
        visited[c.x][c.y] = true;
        if(board[c.x][c.y] == '*'){
            for(int i = 0 ; i < dirty_cnt ; i++){
                if(dirty[i].first == c.x && dirty[i].second == c.y){
                    how_far[i] = c.value;
                    break;
                }
            }
        }
        n.value = c.value+1;
        for(int i = 0 ; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > M-1 || board[n.x][n.y] == 'x') continue;
            pq.push(n);
        }
    }
    for(int i = 0 ; i < dirty_cnt ; i++){
        if(how_far[i] == -1) return false;
    }
    return true;
    
}
int get(int x,int y, int not_clean){
    if(not_clean == 0) return 0;
    
    int& ret = cashe[x][y][not_clean];
    if(ret != -1) return ret;
    ret = 9876543;
    
    
    int how_far[12];
    memset(how_far,-1,sizeof(how_far));
    if(!bfs(x, y,how_far)) return -1;

    
    for(int i = 0 ; i < dirty_cnt ; i++){
        if(not_clean & (1<<i)){
            ret = min(ret, get(dirty[i].first, dirty[i].second, not_clean & ~(1<<i)) + how_far[i]) ;
        }
    }
    //cout<<how_far[0]<<" "<<how_far[1]<<" "<<how_far[2]<<" "<<ret<<"\n";
    
    return ret;
}

int main(void){
    
    while(1){
        if(input()) break;
        memset(cashe,-1,sizeof(cashe));
        cout<<get(f.first,f.second,(1<<dirty_cnt)-1)<<"\n";
    }
}