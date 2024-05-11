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
int board[22][22];
vector<pair<pos,pos>> pick2zero; //pickzero.first.x pickzero.second.y등으로 접근
vector<pos> zero;
void input(){
    cin>>maxx>>maxy;
    pos newpos;
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++){
            cin>>board[i][j];
            if(board[i][j] == 0){
                newpos = {i,j};
                zero.push_back(newpos);
            }
        }
    
    for(int i = 0 ; i < zero.size()-1 ; i++)
        for(int j = i+1 ; j < zero.size() ; j++)
            pick2zero.push_back(make_pair(zero[i], zero[j]));
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool checkboard[22][22];
int bfs(int fx, int fy){
    bool is_it_zero = false;
    int returncnt = 0;
    pos nowpos = {fx,fy};
    pos newpos;
    queue<pos> pq;
    pq.push(nowpos);
    checkboard[fx][fy] = true;
    
    while(!pq.empty()){
        nowpos = pq.front();
        pq.pop();
        returncnt++;
        for(int i = 0 ; i < 4 ; i++){
            newpos.x = nowpos.x + dx[i];
            newpos.y = nowpos.y + dy[i];

            if(newpos.x < 0 || newpos.x > maxx-1 || newpos.y < 0 || newpos.y > maxy-1 || checkboard[newpos.x][newpos.y]) continue;

            if(board[newpos.x][newpos.y] == 2) pq.push(newpos);
            else if(board[newpos.x][newpos.y] == 0){
                is_it_zero = true;
                continue;
            }
            checkboard[newpos.x][newpos.y] = true;
        }
    }

    if(is_it_zero) return 0;
    else return returncnt;
}
int getone(){
    memset(checkboard,false,sizeof(checkboard));
    int cnt = 0;
    for(int i = 0 ; i < maxx ; i++){
        for(int j = 0 ; j < maxy ; j++){
            if(board[i][j] == 2 && !checkboard[i][j]){
                cnt += bfs(i,j);
            }
        }
    }
    
    return cnt;
}

int getresult(){
    int maxresult = 0;
    for(int i = 0 ; i < pick2zero.size() ; i++){
        // pickzero[i].first.x pickzero[i].first.y pickzero.second.x pickzero.second.y
        board[pick2zero[i].first.x][pick2zero[i].first.y] = 1;
        board[pick2zero[i].second.x][pick2zero[i].second.y] = 1;
        
        maxresult = max(maxresult,getone());
        
        board[pick2zero[i].first.x][pick2zero[i].first.y] = 0;
        board[pick2zero[i].second.x][pick2zero[i].second.y] = 0;
    }
    return maxresult;
}

int main(void){
    input();
    cout<<getresult();
}





