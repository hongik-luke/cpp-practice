//14503 내일해보기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int maxx,maxy;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int board[55][55];

struct pos{
    int x;
    int y;
    int type;
};
pos first;

void input(){
    cin>>maxx>>maxy;
    cin>>first.x>>first.y>>first.type;
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            cin>>board[i][j];

}

int nexttype(int type){
    if(type == 0) return 3;
    else return type-1;
}

int getresult(){
    int resultcnt = 0;
    bool near_zero_yes = false;
    pos nowpos,newpos;
    queue <pos> pq;
    pq.push(first);
    while(!pq.empty()){
        nowpos = pq.front();
        pq.pop();

        if(board[nowpos.x][nowpos.y] == 0){
            board[nowpos.x][nowpos.y] = 2;
            resultcnt++;
        }
        
        near_zero_yes = false;
        for(int i = 0 ; i < 4 ; i++){
            newpos.x = nowpos.x + dx[i];
            newpos.y = nowpos.y + dy[i];
            if(board[newpos.x][newpos.y] == 0){
                near_zero_yes = true;
                break;
            }
        }

        newpos.type = nowpos.type;
        if(!near_zero_yes){
            newpos.x = nowpos.x + dx[nexttype(nexttype(nowpos.type))];
            newpos.y = nowpos.y + dy[nexttype(nexttype(nowpos.type))];
            
            
            if(board[newpos.x][newpos.y] == 1) return resultcnt;
            else pq.push(newpos);
        }
        else{
            for(int i = 0; i < 4 ; i++){
                newpos.type = nexttype(newpos.type);
                newpos.x = nowpos.x + dx[newpos.type];
                newpos.y = nowpos.y + dy[newpos.type];

                if(board[newpos.x][newpos.y] == 0){
                    pq.push(newpos);
                    break;
                }
            }
        }
    }
    return -1;
}

int main(void){
    input();
    cout<<getresult()<<"\n";
}





