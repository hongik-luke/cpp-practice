#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M;
char board[52][52];
pair<int,int> f;
void input(){
    cin>>N>>M;
    char n;
    for(int i = 0 ; i  < N ; i++){
        for(int j = 0 ; j  < M ; j++){
            cin>>n;
            if(n == '0'){
                f = {i,j};
                board[i][j] = '.';
            }
            board[i][j] = n;
        }
    }
}
struct pos{
    int x;
    int y;
    int key;
    int value;
};

bool visited[52][52][1<<7];
int bfs(){
    memset(visited,false,sizeof(visited));
    pos cpos,npos;
    queue<pos> pq;
    cpos = {f.first,f.second,0,0};
    pq.push(cpos);
    while(!pq.empty()){
        cpos = pq.front();
        pq.pop();
        //cout<<cpos.x<<" "<<cpos.y<<" "<<cpos.key<<"\n";
        if(board[cpos.x][cpos.y] == '1') return cpos.value;
        
        if(visited[cpos.x][cpos.y][cpos.key]) continue;
        visited[cpos.x][cpos.y][cpos.key] = true;
        
        
        for(int i = 0 ; i < 4 ; i++){
            npos.x = cpos.x + dx[i];
            npos.y = cpos.y + dy[i];
            npos.key = cpos.key;
            npos.value = cpos.value+1;
            if(npos.x < 0 || npos.x > N-1 || npos.y < 0 || npos.y > M-1 || visited[npos.x][npos.y][npos.key] || board[npos.x][npos.y] == '#') continue;
            
            if(board[npos.x][npos.y] >= 'A' && board[npos.x][npos.y] <= 'F'){
                int word = (int)board[npos.x][npos.y] - (int)'A';
                if((npos.key & (1<<word))){
                    pq.push(npos);
                }
                else continue;
            }
            else if(board[npos.x][npos.y] >= 'a' && board[npos.x][npos.y] <= 'f'){
                int word = (int)board[npos.x][npos.y] - (int)'a';
                npos.key = cpos.key | (1<<word);
                pq.push(npos);
            }
            else{
                pq.push(npos);
            }
        }
        
    }
    return -1;
    
}

int main(void){
    input();
    cout<<bfs();
}


