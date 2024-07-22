#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int board[22][22];

void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
        }
    }
}


int main() {
    input();
    for(int k = 0; k < N ;k++){
        for(int i = N-1 ; i >= 0 ; i--){
            for(int j = i ; j < N ; j++){
                if(i == j || i == k || j == k || board[k][j] == 0 || board[i][k] == 0 || board[i][j] == 0) continue;
                
                if(board[i][j] > board[i][k] + board[k][j]){
                    cout<<-1;
                    return 0;
                }
                else if(board[i][j] == board[i][k] + board[k][j]){
                    board[i][j] = 0;
                }
            }
        }
    }
    int ret = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = i+1 ; j < N ; j++){
            if(board[i][j] != 0 && board[i][j] == board[j][i]) ret += board[i][j];
        }
    }
    cout<<ret;
}