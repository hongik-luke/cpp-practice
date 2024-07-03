#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N;
int vlen;
char board[7][7];
vector<pair<int,int>> v;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
            if(board[i][j] == 'X'){
                v.push_back(make_pair(i,j));
            }
        }
    }
    vlen = v.size();
}
bool check(int i1,int i2, int i3){
    board[v[i1].first][v[i1].second] = 'O';
    board[v[i2].first][v[i2].second] = 'O';
    board[v[i3].first][v[i3].second] = 'O';
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(board[i][j] == 'T'){
                int x = i;
                int y = j;
                for(int k = 0 ; k < 4 ; k++){
                    int cnt = 1;
                    while(1){
                        int nx = i + dx[k]*cnt;
                        int ny = j + dy[k]*cnt;
                        if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1 || board[nx][ny] == 'O') break;
                        if(board[nx][ny] == 'S') return false;
                        
                        cnt++;
                    }
                }
            }
        }
        
    }
    return true;
}


bool get(){
    for(int i1 = 0 ; i1 < vlen-2 ; i1++){
        for(int i2 = i1+1 ; i2 < vlen-1 ; i2++){
            for(int i3 = i2+1 ; i3 < vlen ; i3++){
                if(check(i1,i2,i3)) return true;
                else{
                        board[v[i1].first][v[i1].second] = 'X';
                        board[v[i2].first][v[i2].second] = 'X';
                        board[v[i3].first][v[i3].second] = 'X';
                }
            }
        }
    }
    return false;
}
int main(void){
    input();
    if(get()) cout<<"YES";
    else cout<<"NO";
}