#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int maxx,maxy;
char board[55][55];
int firstx,firsty;
void input(){
    cin>>maxx>>maxy;
    for(int i = 0 ; i < maxx ; i++){
        for(int j = 0 ; j < maxy ; j++){
            cin>>board[i][j];
            if(board[i][j] == 'S'){
                firstx = i;
                firsty = j;
            }
            
        }
    }
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct pos{
    int pass_t;
    int near_t;
    int x;
    int y;
};
struct cmp{
    bool operator()(pos a ,pos b){
        if(a.pass_t > b.pass_t)
            return 1;
        else if(a.pass_t == b.pass_t)
            return a.near_t > b.near_t;
        else
            return 0;
    }
};
bool visited[55][55];
void getresult(){
    pos newpos;
    pos nowpos = {0,0,firstx,firsty};
    priority_queue<pos,vector<pos>,cmp> pq;
    pq.push(nowpos);
    
    while(!pq.empty()){
        nowpos = pq.top();
        pq.pop();
        
        if(visited[nowpos.x][nowpos.y]) continue;
        visited[nowpos.x][nowpos.y] = true;
        //cout<<nowpos.pass_t<<" "<<nowpos.near_t<<" "<<nowpos.x<<" "<<nowpos.y<<"\n";
        for(int i = 0 ; i< 4 ; i++){
            newpos.x = nowpos.x + dx[i];
            newpos.y = nowpos.y + dy[i];
            if(newpos.x < 0 || newpos.x > maxx-1 || newpos.y < 0 || newpos.y > maxy-1 || visited[newpos.x][newpos.y]) continue;
            
            if(board[newpos.x][newpos.y] == 'F'){
                cout<<nowpos.pass_t<<" "<<nowpos.near_t;
                return;
            }
            else if(board[newpos.x][newpos.y] == 'g'){
                newpos.pass_t = nowpos.pass_t+1;
                newpos.near_t = nowpos.near_t;
                pq.push(newpos);
            }
            else{
                bool is_trash = false;
                int checkingx,checkingy;
                for(int j = 0 ; j < 4 ; j++){
                    checkingx = newpos.x + dx[j];
                    checkingy = newpos.y + dy[j];
                    if(checkingx < 0 || checkingx > maxx-1 || checkingy < 0 || checkingy > maxy-1 ) continue;
                    if(board[checkingx][checkingy] == 'g'){
                        is_trash = true;
                        break;
                    }
                }
                if(is_trash){
                    newpos.pass_t = nowpos.pass_t;
                    newpos.near_t = nowpos.near_t+1;
                    pq.push(newpos);
                }
                else{
                    newpos.pass_t = nowpos.pass_t;
                    newpos.near_t = nowpos.near_t;
                    pq.push(newpos);
                }
                
            }
        }
    }
}

int main(void){
    input();
    getresult();
}