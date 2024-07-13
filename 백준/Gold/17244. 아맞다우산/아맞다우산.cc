#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int N,M;
char board[55][55];
pair<int,int> F,L;
vector<pair<int,int>> v;
int vlen;

void input(){
    cin>>M>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
            if(board[i][j] == 'S') F = make_pair(i,j);
            if(board[i][j] == 'X') v.push_back(make_pair(i,j));
            if(board[i][j] == 'E') L = make_pair(i,j);
        }
    }
    vlen = v.size();
}
bool check[55][55];
int dis(pair<int,int> a , pair<int,int> b){
    memset(check,false,sizeof(check));
    queue<pair<pair<int,int>,int>> q;
    pair<pair<int,int>,int> n,c;
    
    q.push(make_pair(a,0));
    check[a.first][a.second] = true;
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(c.first.first == b.first && c.first.second == b.second) return c.second;
        
        for(int i = 0 ; i < 4 ;i ++){
            n.first.first = c.first.first + dx[i];
            n.first.second =c.first.second + dy[i];
            if(n.first.first < 0 || n.first.first > N-1 || n.first.second < 0 || n.first.second > M-1 || board[n.first.first][n.first.second] == '#' || check[n.first.first][n.first.second]) continue;
            n.second = c.second+1;
            q.push(n);
            check[n.first.first][n.first.second] = true;
        }
    }
    
    return 98761;
}

int get(pair<int,int> now, int bit){
    if(bit == 0){
        return dis(now,L);
    }
    int dist =98765432;
    for(int i = 0 ; i < vlen ; i ++){
        if(((1<<i) & bit) != 0){
            dist = min(dist, get(v[i],bit-(1<<i))+dis(now,v[i]));
        }
    }
    return dist;
}

int main(void){
    input();
    cout<<get(F,(1<<vlen)-1);
}