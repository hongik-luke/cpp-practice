#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int X,Y;
int board[510][510];
int dp[510][510];
bool visit[510][510];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


struct pos{
    int value;
    int xplace;
    int yplace;
    
};

struct cmp {
    bool operator()(pos a, pos b) {
        return a.value < b.value;
    }
};

priority_queue <pos,vector<pos>, cmp> pq; 

void get(){
    cin>>X>>Y;
    for(int i = 1; i <= X ; i++)
        for(int j = 1; j <= Y ; j++)
            cin>>board[i][j];
    
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    memset(visit,false,sizeof(visit));
    
    
}

void getresult(){
    pos nowpos = {board[1][1],1,1};
    pos newpos;
    pq.push(nowpos);
    visit[nowpos.xplace][nowpos.yplace] = true;
    while(!pq.empty()){
        nowpos = pq.top();
        pq.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            newpos.xplace = nowpos.xplace + dx[i];
            newpos.yplace = nowpos.yplace + dy[i];
            //갈수 있는 곳인지
            if(newpos.xplace <= 0 || newpos.yplace <= 0 || newpos.xplace > X ||newpos.yplace > Y)
                continue;
            //조건에 맞는 곳인지
            newpos.value = board[newpos.xplace][newpos.yplace];
            if(newpos.value < nowpos.value){
                
                dp[newpos.xplace][newpos.yplace] += dp[nowpos.xplace][nowpos.yplace];
                
                if(!visit[newpos.xplace][newpos.yplace])
                    pq.push(newpos);
                visit[newpos.xplace][newpos.yplace] = true;
            }
        }
    }
    
    
}


int main(void){
    get();
    getresult();
    cout<<dp[X][Y]<<"\n";
    
    for(int i = 1; i <= X ; i++){
        for(int j = 1; j <= Y ; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    
}







