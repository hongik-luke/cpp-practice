#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int min_result = 987654321;
int dx[] = {0,0,-1,1}; int dy[] = {-1,1,0,0};
int N,M;
int board[55][55];
pair<int,int> home[105]; pair<int,int> chicken[15];
int hnum = 0; int cnum = 0;
void input(){
    cin>>N>>M;
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
            if(board[i][j] == 1){
                home[hnum++] = make_pair(i,j);
            }
            if(board[i][j] == 2){
                chicken[cnum++] = make_pair(i,j);
            }
        }
    }
}

int h_c_board[105][15];
struct pos{
    int x;
    int y;
    int value;
};
bool visited[55][55];
void bfs(int idx){
    memset(visited,false,sizeof(visited));
    pair<int,int> h = home[idx];
    queue<pos> pq;
    pos cpos,npos;
    cpos = {h.first,h.second,0};
    pq.push(cpos);
    
    while(!pq.empty()){
        cpos = pq.front();
        pq.pop();
        
        if(visited[cpos.x][cpos.y]) continue;
        visited[cpos.x][cpos.y] = true;
        if(board[cpos.x][cpos.y] == 2){
            int i;
            for(i = 0 ; i < cnum ; i++){
                if(chicken[i].first == cpos.x && chicken[i].second == cpos.y) break;
            }
            h_c_board[idx][i] = cpos.value;
        }
        npos.value = cpos.value+1;
        for(int i = 0 ; i < 4 ; i++){
            npos.x = cpos.x + dx[i];
            npos.y = cpos.y + dy[i];
            
            if(npos.x  < 0 || npos.x > N-1 || npos.y  < 0 || npos.y > N-1 || visited[npos.x][npos.y]) continue;
            pq.push(npos);
        }
        
    }
}

void makeh_c_board(){
    for(int i = 0 ; i < hnum ; i++)
        bfs(i);
}

int arr[15];
bool pick[15];

int get(){
    int ret = 0;
    for(int i = 0 ; i < hnum ; i++){
        int min_h = 987654321;
        for(int j = 0 ; j < cnum ; j++){
            if(pick[j]){
                min_h = min(min_h,h_c_board[i][j]);
            }
        }
        ret += min_h;
    }
    return ret;
}
void pick_n_getresult(int now, int many){
    if(many == M){
        for(int i = 0 ; i < M ; i++){
            pick[arr[i]] = true;
        }
        min_result = min(min_result,get());
        memset(pick,false,sizeof(pick));
    }
    
    for(int next = now+1 ; next < cnum ; next++){
        arr[many] = next;
        pick_n_getresult(next,many+1);
    }
}

int main(void){
    input();
    makeh_c_board();
    pick_n_getresult(-1,0);
    cout<<min_result;
}