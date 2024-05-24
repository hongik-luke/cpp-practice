#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct pos{
    int x;
    int y;
    int type;
    int value;
};
int dx[] = {0,0,-1,1}; 
int dy[] = {-1,1,0,0};//서 동 남 북
int c_dx[] = {-1,0,1,-1,0,1,-1,0,1}; 
int c_dy[] = {-1,-1,-1,0,0,0,1,1,1};
int N;
int board[55][55];
pos B = {0,0,0,0};
pos E;
void input(){
    int bidx = 0;
    int eidx = 0;
    pair<int,int> b[5],e[5];
    cin>>N;
    char n;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>n;
            if(n == 'B'){
                b[bidx] = make_pair(i,j);
                bidx++;
                board[i][j] = 0;
            }
            else if(n == 'E'){
                e[eidx] = make_pair(i,j);
                eidx++;
                board[i][j] = 0;
            }
            else if(n == '1') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    if(b[0].first == b[1].first && b[1].first == b[2].first) B = {b[1].first,b[1].second,0,0};
    else B = {b[1].first,b[1].second,1,0};
    if(e[0].first == e[1].first && e[1].first == e[2].first) E = {e[1].first,e[1].second,0,0};
    else E = {e[1].first,e[1].second,1,0};

}
bool visited[55][55][2]; // x y type (type=0 누워있음 type=1 서있음)
int getbfs(){
    queue<pos> pq;
    pq.push(B);
    pos cpos,npos;
    while(!pq.empty()){
        cpos = pq.front();
        pq.pop();
    
        if(cpos.x == E.x && cpos.y == E.y && cpos.type == E.type){
            return cpos.value;
        }
        if(visited[cpos.x][cpos.y][cpos.type]) continue;
        visited[cpos.x][cpos.y][cpos.type] = true;
        //cout<<cpos.x<<" "<<cpos.y<<" "<<cpos.type<<" "<<cpos.value<<"\n";
        
        if(!visited[cpos.x][cpos.y][(cpos.type+1)%2]){
            bool spin_check = true;
            for(int i = 0 ; i < 9 ; i++){
                npos.x = cpos.x + c_dx[i];
                npos.y = cpos.y + c_dy[i];
                if(npos.x < 0 || npos.x > N-1 || npos.y < 0 || npos.y > N-1 || board[npos.x][npos.y] == 1) spin_check = false;
            }
            if(spin_check){
                npos = {cpos.x,cpos.y,(cpos.type+1)%2,cpos.value+1};
                pq.push(npos);
            } 
        }   
                
        if(cpos.type == 0){
            npos.type = cpos.type;
            for(int i = 0 ; i < 4 ; i++){
                npos.x = cpos.x + dx[i];
                npos.y = cpos.y + dy[i];
                if(npos.x < 0 || npos.x > N-1 || npos.y-1 < 0 || npos.y+1 > N-1 || visited[npos.x][npos.y][npos.type]) continue;
                if(board[npos.x][npos.y-1] == 0 && board[npos.x][npos.y] == 0 && board[npos.x][npos.y+1] == 0){
                    npos.value = cpos.value+1;
                    pq.push(npos);
                }
            }
        }
        else{
            npos.type = cpos.type;
            for(int i = 0 ; i < 4 ; i++){
                npos.x = cpos.x + dx[i];
                npos.y = cpos.y + dy[i];
                if(npos.x-1 < 0 || npos.x+1 > N-1 || npos.y < 0 || npos.y > N-1 || visited[npos.x][npos.y][npos.type]) continue;
                if(board[npos.x-1][npos.y] == 0 && board[npos.x][npos.y] == 0 && board[npos.x+1][npos.y] == 0){
                    npos.value = cpos.value+1;
                    pq.push(npos);
                }
            }
        }
        
    }
    
    return 0;
}

int main(void){
    input();
    cout<<getbfs();
}
