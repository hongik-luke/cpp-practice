//14503 내일해보기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int maxx,maxy;
int mover[] = {8,4,2,1};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int maxfor2 = 0;

int board[55][55];

int idxfor1 = 1;
int idxboard[55][55];
int idxnum[2600];


void input(){
    memset(idxboard,0,sizeof(idxboard));
    cin>>maxy>>maxx;
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            cin>>board[i][j];

}



bool checkboard[55][55];

int bfs(int x,int y){
    int nowcnt = 0;
    int cx,cy,nx,ny;
    
    queue<pair<int,int>> pq;
    pq.push(make_pair(x,y));
    checkboard[x][y] = true;
    idxboard[x][y] = idxfor1;
    
    while(!pq.empty()){
        cx = pq.front().first;
        cy = pq.front().second;
        pq.pop();
        
        nowcnt++;
        
        int nowboard = board[cx][cy];
        for(int i = 0 ; i < 4 ;i++){
            if(nowboard - mover[i] >= 0){
                nowboard -= mover[i];
                continue;
            }
            
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx < 0 || nx > maxx-1 || ny < 0 || ny > maxy -1 || checkboard[nx][ny]) continue;
            
            checkboard[nx][ny] = true;
            idxboard[nx][ny] = idxfor1;
            pq.push(make_pair(nx,ny));
        }
    }
    
    idxnum[idxfor1] = nowcnt;
    return nowcnt;
}
void getall(){
    for(int i = 0 ; i < maxx ; i++){
        for(int j = 0 ; j < maxy ; j++){
            if(idxboard[i][j] == 0){
                memset(checkboard,false,sizeof(checkboard));
                maxfor2 = max(maxfor2,bfs(i,j));
                idxfor1++;
            }
        }
    }
}
int hapboardmax(){
    int returnmax = 0;
    for(int i = 0 ; i < maxx ; i++){
        for(int j = 0 ; j < maxy ; j++){
            if(j != maxy-1 && idxboard[i][j] != idxboard[i][j+1]){
                returnmax = max(returnmax, idxnum[idxboard[i][j]] + idxnum[idxboard[i][j+1]]);
            }
            
            if(i != maxx-1 && idxboard[i][j] != idxboard[i+1][j]){
                returnmax = max(returnmax, idxnum[idxboard[i][j]] + idxnum[idxboard[i+1][j]]);
            }
        }
    }
    
    return returnmax;
}

int main(void){
    input();
    getall();
    cout<<idxfor1-1<<"\n"<<maxfor2<<"\n";
    cout<<hapboardmax()<<"\n";
}





