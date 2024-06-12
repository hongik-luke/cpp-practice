#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int board[104][104];
bool check[104];
int N,L;
void input(){
    cin>>N>>L;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
        }
    }
}
bool get_row(int idx){
    memset(check,false,sizeof(check));
    for(int i = 0 ; i < N-1 ; i++){
        if(board[idx][i] == board[idx][i+1]) continue;
        
        if(board[idx][i] > board[idx][i+1]){
            if(board[idx][i] != board[idx][i+1]+1) return false;
            int cnt = 0;
            while(cnt != L){
                cnt++;
                if(i+cnt < 0 || i+cnt > N-1) return false;
                if(check[i+cnt] == true) return false;
                check[i+cnt] = true;
            }
        }
        
        if(board[idx][i] < board[idx][i+1]){
            if(board[idx][i]+1 != board[idx][i+1]) return false;
            
            int cnt = 0;
            while(cnt != L){
                cnt++;
                if(i+1-cnt < 0 || i+1-cnt > N-1) return false;
                if(check[i+1-cnt] == true) return false;
                check[i+1-cnt] = true;
            }
        }
    }
    return true;
}
bool get_column(int idx){
    memset(check,false,sizeof(check));
    for(int i = 0 ; i < N-1 ; i++){
        if(board[i][idx] == board[i+1][idx]) continue;
        
        if(board[i][idx] > board[i+1][idx]){
            if(board[i][idx] != board[i+1][idx]+1) return false;
            int cnt = 0;
            while(cnt != L){
                cnt++;
                if(i+cnt < 0 || i+cnt > N-1) return false;
                if(check[i+cnt] == true) return false;
                check[i+cnt] = true;
            }
        }
        
        if(board[i][idx] < board[i+1][idx]){
            if(board[i][idx]+1 != board[i+1][idx]) return false;
            
            int cnt = 0;
            while(cnt != L){
                cnt++;
                if(i+1-cnt < 0 || i+1-cnt > N-1) return false;
                if(check[i+1-cnt] == true) return false;
                check[i+1-cnt] = true;
            }
        }
    }
    return true;
}
int main(void){
    input();
    int result_cnt = 0;
    for(int i = 0 ; i < N ; i++){
        if(get_row(i)) result_cnt++;
        if(get_column(i)) result_cnt++;
    }
    cout<<result_cnt;
}