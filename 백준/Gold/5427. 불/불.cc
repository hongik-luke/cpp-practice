#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int type;
    int x;
    int y;
};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

vector<pos> f_fire;
pos f_sang;
int maxx,maxy;
bool cant_visited[1010][1010];
void input(){
    memset(cant_visited,false,sizeof(cant_visited));
    f_fire.clear();
    cin>>maxy>>maxx;
    pos npos;
    char n;
    for(int i = 0 ; i < maxx ; i++){
        for(int j = 0 ; j < maxy ; j++){
            cin>>n;
            if(n == '#')
                cant_visited[i][j] = true;
            else if(n == '*'){
                npos = {0,i,j};
                f_fire.push_back(npos);
                cant_visited[i][j] = true;
            }
            else if(n == '@'){
                npos = {1,i,j};
                f_sang = npos;
                cant_visited[i][j] = true;
            }
        }
    }
    
}

int bfs(){
    pos cpos,npos;
    queue<pos> pq;
    for(int i = 0 ; i < f_fire.size() ; i++){
        pq.push(f_fire[i]);
        cant_visited[f_fire[i].x][f_fire[i].y] = true;
    }
    pq.push(f_sang);
    cant_visited[f_sang.x][f_sang.y] = true;
    
    while(!pq.empty()){
        cpos = pq.front();
        pq.pop();

        if(cpos.type == 0){
            npos.type = 0;
            for(int i = 0 ; i < 4 ; i++){
                npos.x = cpos.x + dx[i];
                npos.y = cpos.y + dy[i];
                if(npos.x < 0 || npos.x > maxx-1 || npos.y < 0 || npos.y > maxy-1 || cant_visited[npos.x][npos.y]) continue;
                
                cant_visited[npos.x][npos.y] = true;
                pq.push(npos);
            }
        }
        else{
            npos.type = cpos.type +1;
            for(int i = 0 ; i < 4 ; i++){
                npos.x = cpos.x + dx[i];
                npos.y = cpos.y + dy[i];
                if(npos.x < 0 || npos.x > maxx-1 || npos.y < 0 || npos.y > maxy-1 ) return cpos.type;
                if(cant_visited[npos.x][npos.y]) continue;
                
                cant_visited[npos.x][npos.y] = true;
                pq.push(npos);
            }
        }
    }

    
    return -1;
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin>>TC;
    for(int i = 0 ; i< TC ; i++){
        input();
        int result = bfs();
        if(result == -1) cout<<"IMPOSSIBLE"<<"\n";
        else cout<<result<<"\n";
    }
}