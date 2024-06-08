#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N;
int min_ = 98765432;
int board[12][12];
bool check[12];
void input(){
    cin>>N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin>>board[i][j];
        }
    }
}

void get(int value, int now){
    
    for(int i = 0 ; i < N ; i++){
        if(board[now][i] == 0 || check[i] == true) continue;
        check[i] = true;
        get(value+board[now][i], i);
        check[i] = false;
    }
    
    for(int i = 0 ; i < N; i++)
        if(!check[i]) return;
    
    if(board[now][0] != 0){
        min_ = min(min_, value+board[now][0]);
    }
}
int main(void){
    input();
    check[0] = true;
    get(0,0);
    cout<<min_;
}