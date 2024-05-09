#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int N,M,K;
int board[106][106];
bool check[106][106];

struct pos{
    int x;
    int y;
};

int dx[] ={1,-1,0,0};
int dy[] ={0,0,1,-1};

void input(){
    memset(check,false,sizeof(check));
    cin>>N>>M>>K;
    int x,y;
    for(int i = 0 ; i < K ;i++){
        cin>>x>>y;
        board[x][y] = 1;
    }
    
}

int get(int x ,int y){

    queue<pos> pq;
    int cnt = 0;
    pos now,new1;
    now.x = x;
    now.y = y;
    pq.push(now);
    check[x][y] = true;
    
    while(!pq.empty()){
        now = pq.front();
        pq.pop();
        cnt++;
        for(int i = 0 ; i < 4; i++){
            new1.x = now.x + dx[i];
            new1.y = now.y + dy[i];
            if(new1.x <= 0 || new1.x > N || new1.y <= 0 || new1.y > M || check[new1.x][new1.y] == true) continue;
            
            if(board[new1.x][new1.y] == 1)
                pq.push(new1);

            check[new1.x][new1.y] = true;
        }
    }
    
    
    return cnt;
}

int result = 0;
void getresult(){
    
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= M ;j++){
            if(board[i][j] == 1 && check[i][j] == false) {
                result = max(result,get(i,j));
            }
                
        }
        
    }
}


int main(void){
    input();
    getresult();
    cout<<result;
}







