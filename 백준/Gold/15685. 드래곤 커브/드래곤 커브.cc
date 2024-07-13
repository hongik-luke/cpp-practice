#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int arr[20][4];
vector<int> v[20];
void make(int idx, int gen){
    if(gen == 0) return;
    int len = v[idx].size();
    for(int i = 0 ; i < len ; i++){
        v[idx].push_back((v[idx][len-1-i]+1)%4);
    }
    make(idx,gen-1);
}
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
        v[i].push_back(arr[i][2]);
    }
    for(int i = 0 ; i < N ; i++){
        make(i,arr[i][3]);
    }
}
bool board[105][105];
void draw_to_board(){
    for(int i = 0 ; i  < N ; i++){
        int x = arr[i][1];
        int y = arr[i][0];
        board[x][y] = true;
        int t = 0;
        int len = v[i].size();
        for(int t = 0 ; t < len ; t++){
            x += dx[v[i][t]];
            y += dy[v[i][t]];
            board[x][y] = true;
        }
    }
}
int get(){
    int cnt = 0;
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    return cnt;
}
int main(void){
    FASTIO;
    input();
    memset(board,false,sizeof(board));
    draw_to_board();
    cout<<get()<<"\n";
}