#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int maxx,maxy;
struct pos{
    int x;
    int y;
    int value;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }
};
struct disjoint{
    int rank[1505][1505];
    pair<int,int> parent[1505][1505];
    
    pair<int,int> find(pair<int,int> c){
        if(parent[c.first][c.second] == c) return c;
        return parent[c.first][c.second] = find(parent[c.first][c.second]);
    }
    bool merge(pair<int,int> u , pair<int,int> v){
        u = find(u); v = find(v);
        
        if(u.first == v.first && u.second == v.second) return true;
        if(rank[u.first][u.second] > rank[v.first][v.second]) swap(u,v);
        
        parent[u.first][u.second].first =  v.first;
        parent[u.first][u.second].second =  v.second;
        if(rank[u.first][u.second] == rank[v.first][v.second]);
        return false;
    }
};
pair<int,int> L[2];
int board[1505][1505];
bool visited[1505][1505];
priority_queue<pos,vector<pos>,cmp> pq;
void input(){
    cin>>maxx>>maxy;
    char n;
    pos a;
    int cnt = 0;
    for(int i = 0 ; i< maxx ; i++){
        for(int j = 0 ; j< maxy ; j++){
            cin>>n;
            if(n == 'L'){
                L[cnt++] = make_pair(i,j);
                a = {i,j,0};
                pq.push(a);
                board[i][j] = 0;
            }
            else if(n == '.'){
                a = {i,j,0};
                pq.push(a);
                board[i][j] = 0;
            }
            
        }
    }
}
disjoint set;
int bfs(){
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            set.parent[i][j] = make_pair(i,j);
    memset(set.rank,1,sizeof(set.rank));
    
    int cnt1 = 0;
    pos c,n,nn;
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        if(c.value > cnt1){
            if(set.find(L[0]) == set.find(L[1])){
                return c.value;
            }
            else cnt1 = c.value;
        }
        if(visited[c.x][c.y]) continue;
        visited[c.x][c.y] = true;
        
        for(int i = 0; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            n.value = c.value + 1;
            if(n.x < 0 || n.x > maxx-1 || n.y < 0 || n.y > maxy-1 || visited[n.x][n.y]) continue;
            if(board[n.x][n.y] == -1){
                board[n.x][n.y] = n.value;
                pq.push(n);
            }
            if(set.merge(make_pair(c.x,c.y), make_pair(n.x,n.y))) continue;
            for(int i = 0; i < 4 ; i++){
                nn.x = n.x + dx[i];
                nn.y = n.y + dy[i];
                if(nn.x < 0 || nn.x > maxx-1 || nn.y < 0 || nn.y > maxy-1) continue;
                if(board[nn.x][nn.y] != -1) set.merge(make_pair(n.x,n.y), make_pair(nn.x,nn.y));
            }
        }
    }
    if(set.find(L[0]) == set.find(L[1])) return cnt1;
    return -1;
}


int main(void){
    memset(board,-1,sizeof(board));
    memset(visited,false,sizeof(visited));
    input();
    cout<<bfs();
}