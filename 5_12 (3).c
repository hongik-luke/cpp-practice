//2636
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
};

int maxx,maxy;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int board[105][105];


int lastvsize;
vector<pos> v;

void input(){
    cin>>maxx>>maxy;
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            cin>>board[i][j];

}


int checkboard[105][105];
void bfs(){
    pos now = {0,0};
    pos new1;
    queue<pos> pq;
    pq.push(now);
    checkboard[now.x][now.y] = true;
    
    while(!pq.empty()){
        now = pq.front();
        pq.pop();

        for(int i = 0 ; i < 4 ; i++){
            new1.x = now.x + dx[i];
            new1.y = now.y + dy[i];
            
            if(new1.x < 0 || new1.x > maxx-1 || new1.y < 0 || new1.y > maxy-1 || checkboard[new1.x][new1.y]) continue;
            checkboard[new1.x][new1.y] = true;
            
            if(board[new1.x][new1.y] == 1){
                v.push_back(new1);
            }
            else if(board[new1.x][new1.y] == 0){
                pq.push(new1);
            }
        }
    }
    
}

int getresult(){
    int returncnt = 0;
    while(1){
        memset(checkboard,false,sizeof(checkboard));
        v.clear();
        bfs();
        
        lastvsize = v.size();
        for(int i = 0 ; i < v.size() ; i++)
            board[v[i].x][v[i].y] = 0;
        
        returncnt++;
        
        bool is_it_finish = true;
        for(int i = 0 ; i < maxx ; i++)
            for(int j = 0 ; j < maxy ; j++){
                if(board[i][j] == 1) is_it_finish = false;
            }
        if(is_it_finish) return returncnt;
        
    }
    
}

int main(void){
    input();
    cout<<getresult()<<"\n"<<lastvsize<<"\n";
}





