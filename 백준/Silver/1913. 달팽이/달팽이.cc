#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int board[1000][1000];
int N,find_n;
void input(){
    cin>>N>>find_n;    
}
void make_N_print(){
    memset(board,0,sizeof(board));
    int x = N/2; int y = N/2;
    int n = 1;
    int i = 0;
    while(1){
        //cout<<x<<" "<<y<<i<<"\n";
        board[x][y] = n++;
        if(x == 0 && y == 0) break;
        x = x + dx[i]; y = y + dy[i];
        if(board[x+dx[(i+1)%4]][y+dy[(i+1)%4]] == 0) i = (i+1)%4;
    }
    
    int retx,rety;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout<<board[i][j]<<" ";
            if(board[i][j] == find_n){
                retx = i+1;
                rety = j+1;
            }
        }
        cout<<"\n";
    }
    cout<<retx<<" "<<rety;
    
}

int main(void){
    input();
    make_N_print();
}
