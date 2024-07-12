#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,K;
int board[102][102];
void input(){
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin>>board[i][j];
        }
    }
}
bool check[105];
bool get_row(int idx){
    memset(check,false,sizeof(check));
    bool flag = true;
    for(int i = 1 ; i < N ; i++){
        if(board[i][idx] > board[i+1][idx]){
            if(board[i][idx] != board[i+1][idx]+1) return false;
            int cnt = 0;
            int now = board[i+1][idx];
            while(cnt != K){
                if(i+1+cnt < 1 || i+1+cnt > N || board[i+1+cnt][idx] != now || check[i+1+cnt]){
                    flag = false;
                    break;
                }
                check[i+1+cnt] = true;
                cnt++;
            }
            if(!flag) return false;
        }
    }
    for(int i = 1 ; i < N ; i++){
        if(board[i][idx] < board[i+1][idx]){
            if(board[i][idx]+1 != board[i+1][idx]) return false;
            int cnt = 0;
            int now = board[i][idx];
            while(cnt != K){
                if(i-cnt < 1 || i-cnt > N || board[i-cnt][idx] != now || check[i-cnt]){
                    flag = false;
                    break;
                }
                check[i-cnt] = true;
                cnt++;
            }
            if(!flag) return false;
        }
    }
    return true;
}
bool get_column(int idx){
    memset(check,false,sizeof(check));
    bool flag = true;
    for(int i = 1 ; i < N ; i++){
        if(board[idx][i] > board[idx][i+1]){
            if(board[idx][i] != board[idx][i+1]+1) return false;
            int cnt = 0;
            int now = board[idx][i+1];
            while(cnt != K){
                if(i+1+cnt < 1 || i+1+cnt > N || board[idx][i+1+cnt] != now || check[i+1+cnt]){
                    flag = false;
                    break;
                }
                check[i+1+cnt] = true;
                cnt++;
            }
            if(!flag) return false;
        }
    }
    for(int i = 1 ; i < N ; i++){
        if(board[idx][i] < board[idx][i+1]){
            if(board[idx][i]+1 != board[idx][i+1]) return false;
            int cnt = 0;
            int now = board[idx][i];
            while(cnt != K){
                if(i-cnt < 1 || i-cnt > N || board[idx][i-cnt] != now || check[i-cnt]){
                    flag = false;
                    break;
                }
                check[i-cnt] = true;
                cnt++;
            }
            if(!flag) return false;
        }
    }
    return true;
}

int get(){
    int ret = 0;
    for(int i = 1 ; i <= N ; i++){
        if(get_row(i)){
            ret++;
        }
    }
    for(int i = 1 ; i <= N ; i++){
        if(get_column(i)){
            ret++;
        }
    }
    return ret;
}
int main(void){
    input();
    cout<<get();
}