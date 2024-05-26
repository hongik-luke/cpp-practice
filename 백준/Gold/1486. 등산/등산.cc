//1486
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct pos{
    int x;
    int y;
    int value;
};

struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }
};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N,M,T,D;
int board[30][30];
void input(){
    cin>>N>>M>>T>>D;
    char c;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>c;
            if(c >= 'A' && c <= 'Z'){
                board[i][j] = (int)c - (int)'A';
            }
            else{
                board[i][j] = (int)c - (int)'a' + 26;
            }
        }
    }
}
int aboard[30][30];
void makea(){
    memset(aboard,-1,sizeof(aboard));
    pos cpos,npos;
    priority_queue<pos,vector<pos>,cmp> pq;
    cpos = {0,0,0};
    pq.push(cpos);
    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        
        if(aboard[cpos.x][cpos.y] != -1) continue;
        aboard[cpos.x][cpos.y] = cpos.value;
        
        for(int i = 0 ; i < 4 ; i++){
            npos.x = cpos.x + dx[i];
            npos.y = cpos.y + dy[i];
            
            if(npos.x < 0 || npos.x > N-1 || npos.y < 0 || npos.y > M-1 || aboard[npos.x][npos.y] != -1) continue;
            if(abs(board[npos.x][npos.y] - board[cpos.x][cpos.y]) > T) continue;
            
            if(board[cpos.x][cpos.y] < board[npos.x][npos.y]){
                npos.value = cpos.value + (board[npos.x][npos.y] - board[cpos.x][cpos.y])*(board[npos.x][npos.y] - board[cpos.x][cpos.y]);
            }
            else{
                npos.value = cpos.value+1;
            }
            pq.push(npos);
        }
        
    }
}

bool visited[30][30];
int get_top_a(pos n){
    memset(visited,false,sizeof(visited));
    pos cpos, npos;
    priority_queue <pos,vector<pos>,cmp> p;
    cpos = {n.x,n.y,0};
    p.push(cpos);
    while(!p.empty()){
        cpos = p.top();
        p.pop();
        
        if(cpos.x == 0 && cpos.y == 0) return cpos.value;
        if(visited[cpos.x][cpos.y]) continue;
        visited[cpos.x][cpos.y] = true;
        //cout<<cpos.x<<" "<<cpos.y<<" "<<cpos.value<<"\n";
        for(int i = 0 ; i < 4 ; i++){
            npos.x = cpos.x + dx[i];
            npos.y = cpos.y + dy[i];
            
            if(npos.x < 0 || npos.x > N-1 || npos.y < 0 || npos.y > M-1 || visited[npos.x][npos.y]) continue;
            if(abs(board[npos.x][npos.y] - board[cpos.x][cpos.y]) > T) continue;
            
            if(board[cpos.x][cpos.y] < board[npos.x][npos.y]){
                npos.value = cpos.value + (board[npos.x][npos.y] - board[cpos.x][cpos.y])*(board[npos.x][npos.y] - board[cpos.x][cpos.y]);
            }
            else{
                npos.value = cpos.value+1;
            }
            //cout<<npos.x<<" "<<npos.y<<" "<<npos.value<<"\n";
            p.push(npos);
        }
        
    }
    return 987654321;
}

int getmax(){
    priority_queue<pos,vector<pos>,cmp> pq;
    pos n;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(aboard[i][j] == -1) continue;
            if(aboard[i][j] > D) continue;
            n = {i,j,-board[i][j]};
            pq.push(n);
        }
    }
    
    while(!pq.empty()){
        n = pq.top();
        pq.pop();
        //cout<<get_top_a(n)<<" "<<aboard[n.x][n.y]<<"_"<<n.x<<n.y<<"\n";
        
        int a = get_top_a(n);
        if(a + aboard[n.x][n.y] <= D) return board[n.x][n.y];
    }
    return 0;
}

int main(void){
    input();
    makea();

    cout<<getmax();
    
}
