#include <iostream>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int board[55][55];
int checkboard[55][55];
int N,M;

void input(){
    cin>>N>>M;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            scanf("%1d",&board[i][j]);
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= M ; j++)
            scanf("%1d",&checkboard[i][j]);
}

bool change(int x,int y){
    if(x+2 > N || y+2 > M) return false;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[i+x][j+y] == 1) board[i+x][j+y] = 0;
            else board[i+x][j+y] = 1;
        }
    }
    return true;
}
int getresult(){
    int result = 0;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(board[i][j] != checkboard[i][j]){
                if(!change(i,j)) return -1;
                else result++;
            }    
        }
    }
    
    return result;
}
int main(void){
    input();
    cout<<getresult();
}