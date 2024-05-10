//연구소 14502

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
struct pos{
    int x;
    int y;
};

int N,M;
int originalboard[8][8];
int checkboard[8][8];
bool checkbool[8][8];
pos zero_arr[64];
int zero_cnt = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++){
            cin>>originalboard[i][j];
            if(originalboard[i][j] == 0){
                pos newpos = {i,j};
                zero_arr[zero_cnt] = newpos; 
                zero_cnt++;
            }
        }
    
}
void resetboard(){
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            checkboard[i][j] = originalboard[i][j];
}
void dfs(int i,int j){
    
    pos now;
    now.x = i;
    now.y = j;
    pos new1;
    
    queue<pos> pq;
    pq.push(now);
    checkbool[i][j] = true;
    while(!pq.empty()){
        now = pq.front();
        pq.pop();
        for(int i = 0 ; i < 4 ; i++){
            new1.x = now.x + dx[i];
            new1.y = now.y + dy[i];
            if(new1.x < 0 || new1.x > N-1 || new1.y < 0 || new1.y > M-1 || checkbool[new1.x][new1.y] == true) continue;
            
            checkbool[new1.x][new1.y] = true;
            if(checkboard[new1.x][new1.y] == 1) continue;
            
            checkboard[new1.x][new1.y] = 2;
            pq.push(new1);
        }
    }
    return;
}


int get(){
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++){
            if(checkboard[i][j] == 2 && checkbool[i][j] == false){
                dfs(i,j);
            }
        }
        
    int cnt = 0;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++){
            if(checkboard[i][j] == 0) cnt++;
        }
    
    return cnt;
}

int result = 0;
int getresult(){
    resetboard();
    int rmax = -1;
    for(int i = 0 ; i <= zero_cnt-3 ; i++){
        for(int j = i+1 ; j <= zero_cnt-2 ; j++){
            for(int k = j+1 ; k <= zero_cnt-1 ; k++){
                checkboard[zero_arr[i].x][zero_arr[i].y] = 1;
                checkboard[zero_arr[j].x][zero_arr[j].y] = 1;
                checkboard[zero_arr[k].x][zero_arr[k].y] = 1;
                
                memset(checkbool,false,sizeof(checkbool));
                rmax = max(rmax,get());
                resetboard();
            }
        }
    }
    
    return rmax;
    
}


int main(void){
    input();
    resetboard();
    cout<<getresult();

}







