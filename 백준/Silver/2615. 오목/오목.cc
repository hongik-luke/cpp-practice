#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int board[20][20];
void input(){
    for(int i = 1 ; i <= 19 ; i++)
        for(int j = 1 ; j <= 19 ; j++)
            cin>>board[i][j];
    
}
int dx[] = {-1,0,1,1};
int dy[] = {1,1,1,0};
bool check(int x, int y){
    for(int i = 0 ; i < 4 ; i++){
        bool check1 = true;
        bool check2 = true;
        int nx,ny;
        nx = x + dx[i]*5; ny = y + dy[i]*5;
        if(nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19)
            if(board[nx][ny] == board[x][y]) check2 = false;
            
        nx = x + dx[i]*-1; ny = y + dy[i]*-1;
        if(nx >= 1 && nx <= 19 && ny >= 1 && ny <= 19)
            if(board[nx][ny] == board[x][y]) check2 = false;
        if(!check2) continue;    


        for(int j = 1 ; j < 5 ; j++){
            nx = x + dx[i]*j;
            ny = y + dy[i]*j;
            if(nx < 1 || nx > 19 || ny < 1 || ny > 19 || board[nx][ny] != board[x][y]){
                check1 = false;
                break;
            }
        }
        if(check1) return true;
        
    }
    return false;
}

void get_show_result(){
    for(int j = 1 ; j <= 19 ; j++){
        for(int i = 1 ; i <= 19 ; i++){
            if(board[i][j] != 0){
                if(check(i,j)){
                    cout<<board[i][j]<<"\n"<<i<<" "<<j<<"\n";
                    return;
                }
            }
        }
    }
    cout<<0;

}

int main(void){
    input();
    get_show_result();
}