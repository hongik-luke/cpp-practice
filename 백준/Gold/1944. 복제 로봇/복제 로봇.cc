#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M;
char board[55][55];
pair<int,int> location[300];

struct pos {
    int x;
    int y;
    int num;
};
void input(){
    cin>>N>>M;
    string str;
    int cnt = 1;
    for(int i = 0; i < N ; i++){
        cin>>str;
        for(int j = 0; j < N ; j++){
            board[i][j] = str[j];
            if(board[i][j] == 'S') location[0] = {i,j}; 
            else if(board[i][j] == 'K') location[cnt++] = {i,j}; 
        }
    }
}
vector<pair<int,int>> v[300];

bool visited[55][55];
void get(int start){
    memset(visited,false,sizeof(visited));
    queue<pos> q;
    pos c,n;
    c = {location[start].first ,location[start].second ,0};
    q.push(c);
    visited[location[start].first][location[start].second] = true; 
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(board[c.x][c.y] == 'S' || board[c.x][c.y] == 'K'){
            
            for(int i = 0; i <= M ; i++){
                if(c.x == location[i].first && c.y == location[i].second){
                    if(c.num == 0) break;
                    v[i].push_back({start, c.num});
                    break;
                }
            }
        }
        
        for(int i = 0 ;i < 4 ; i++){
            n.x = c.x+dx[i];
            n.y = c.y+dy[i];
            n.num = c.num+1;
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > N-1 || visited[n.x][n.y] || board[n.x][n.y] == '1') continue;
            
            q.push(n);
            visited[n.x][n.y] = true;
        }
    }
}
struct cmp{
    bool operator()(pair<int,int> a ,pair<int,int> b){
        return a.second > b.second;
    }
};
int ret = 0;
bool check[300];
bool get_result(){
    memset(check,false,sizeof(check));
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({0,0});
    pair<int,int> c,n;
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        
        if(check[c.first]) continue;
        check[c.first] = true;
        ret += c.second;

        int len = v[c.first].size();
        for(int i = 0 ; i < len ; i++){
            if(check[v[c.first][i].first]) continue;
            pq.push({v[c.first][i].first, v[c.first][i].second});
        }
    }
    for(int i = 0; i <= M ; i++)
        if(!check[i]) return true;
    
    return false;
}

int main(){
    input();
    for(int i = 0 ; i <= M ; i++)
        get(i);
    
    if(get_result()) cout<<-1;
    else cout<<ret;
}