#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int N,M,K;
int l[2010][2010];
char board[2010][2010];
void input(){
    cin>>N>>M>>K;
    for(int i = 0 ;i < N ;i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
        }
    }

}
void get_one(int row){
    int now = 0;
    for(int i = 0 ; i < K ;i++){
        if((i+row)%2 == 0 && board[row][i] == 'W'){
            now++;
        }
        if((i+row)%2 == 1 && board[row][i] == 'B'){
            now++;
        }
    }
    l[row][0] = now;      //6
    
    for(int i = K ; i < M ; i++){
        now = K - now;
        if((row)%2 == 0 && board[row][i-K] == 'B') now--;
        else if((row)%2 == 1 && board[row][i-K] == 'W') now--;

        if((row+K-1)%2 == 0 && board[row][i] == 'W') now++;
        else if((row+K-1)%2 == 1 && board[row][i] == 'B') now++;
        l[row][i-K+1] = now;
        now = l[row][i-K+1];   
    }
}
int get(){
    for(int i = 0; i < N ; i++){
        get_one(i);
    }
    
    int ret = 1e9;
    for(int j = 0 ; j <= M-K ; j++){
        int now = 0;
        for(int i = 0 ; i < K ; i++){
            now += l[i][j];
        }
        ret = min(now, ret);
        ret = min((K*K)-now, ret);

        for(int i = K ; i < N ;i++){
            now -= l[i-K][j];
            now += l[i][j];
            
            ret = min(now,ret);
            ret = min((K*K)-now, ret);

        }
        
    }
    return ret;
}
int main(void){
    input();
    cout<<get()<<"\n";

}