#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N;
int min_ = 987654321;
bool check[22];
int board[22][22];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
        }
    }
}
int get(){
    int team1 = 0; int team2 = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(check[i] == true && check[j] == true){
                team1 += board[i][j]; 
            }
            if(check[i] == false && check[j] == false){
                team2 += board[i][j]; 
            }
        }
    }
    
    return abs(team1-team2);
}
void make_n_check(int choice, int beforeidx){
    if(choice == N/2){
        min_ = min(min_ ,get());
        return;
    }
    for(int i = beforeidx+1 ; i < N ; i++){
        check[i] = true;
        make_n_check(choice+1, i);
        check[i] = false;
    }
}
int main(void){
    input();
    memset(check,false,sizeof(check));
    make_n_check(0,-1);
    cout<<min_;
}