#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int IMF = 98765432;

int adj[10][10];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int maxx,maxy;
int board[12][12];
int land_board[12][12];
int landcnt = 0;

bool check[12][12];

void makeland(int x, int y){
    queue<pair<int,int>> pq;
    pq.push(make_pair(x,y));
    pair<int,int> c,n;
    
    while(!pq.empty()){
        c = pq.front();
        pq.pop();
        
        if(check[c.first][c.second]) continue;
        check[c.first][c.second] = true;
        land_board[c.first][c.second] = landcnt+1;
        
        for(int i = 0 ; i < 4 ; i++){
            n.first = c.first + dx[i];
            n.second = c.second + dy[i];

            if(n.first < 0 || n.first > maxx-1 || n.second < 0 || n.second > maxy-1 || check[n.first][n.second] || board[n.first][n.second] == 0) continue;

            pq.push(n);
        }
    }
    landcnt++;
}
void make_adj(int land_idx ,int x, int y){
    int cnt = 0;
    int nx,ny;
    for(int i = 0 ; i < 4 ; i++){
        cnt = -1; nx = x; ny = y;
        while(1){
            nx += dx[i]; ny += dy[i]; cnt++;
            if(nx < 0 || nx > maxx-1 || ny < 0 || ny > maxy-1 || land_board[nx][ny] == land_idx) break;
            
            if(land_board[nx][ny] != 0){
                if(cnt == 1) break;
                else{
                    adj[land_idx][land_board[nx][ny]] = min(adj[land_idx][land_board[nx][ny]], cnt);
                    //cout<<land_idx<<" "<<land_board[nx][ny]<<" "<<cnt<<"\n";
                    break;
                }
            }
        }
    }
}
void input_n_makeeverything(){
    memset(check,false,sizeof(check));
    memset(land_board,0,sizeof(land_board));
    fill(&adj[0][0], &adj[8][8] , IMF);
    cin>>maxx>>maxy;
    for(int i = 0 ; i< maxx ; i++)
        for(int j = 0 ; j< maxy ; j++)
            cin>>board[i][j];
    
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++){
            if(board[i][j] == 1 && check[i][j] == false){
                makeland(i,j);
            }
        }
    
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            if(land_board[i][j] != 0) make_adj(land_board[i][j],i,j);
        
    
}
struct pos{
    int value;
    int idx;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }  
};
bool visited[10];
int minimumspaningtree(){
    memset(visited,false,sizeof(visited));
    
    int result = 0;
    
    priority_queue <pos,vector<pos>,cmp> pq;
    pos cpos,npos;
    cpos = {0,1};
    pq.push(cpos);
    
    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        
        if(visited[cpos.idx]) continue;
        visited[cpos.idx] = true;
        result += cpos.value;
        //cout<<cpos.idx<<")"<<cpos.value<<"  ";
        for(int i = 1 ; i <= landcnt ; i++){
            if(adj[cpos.idx][i] == IMF) continue;
            
            if(visited[i]) continue;
            npos = {adj[cpos.idx][i], i};
            pq.push(npos);
        }
    }
    return result;
}


int main(void){
    input_n_makeeverything();
    int result = minimumspaningtree();
    for(int i = 1 ; i<= landcnt ; i++){
        if(!visited[i]){
            cout<<-1; 
            return 0;
        }
    }
    cout<<result;
    return 0;
    
}