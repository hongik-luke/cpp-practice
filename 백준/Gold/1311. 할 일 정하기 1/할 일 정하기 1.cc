#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int board[20][20]; //[i][j] i번째일을 하는데 j번쨰 사람이 걸리는 시간
int cashe[20][1<<20];

void input(){
    cin>>N;
    for(int i = 0 ;  i < N ; i++){
        for(int j = 0 ;  j < N ; j++){
            cin>>board[i][j];
        }
    }
}

int get(int idx , int to_do){
    if(to_do == 0 && idx == N) return 0;
    
    int& ret = cashe[idx][to_do];
    if(ret != -1) return ret;
    ret = 987654321;
    
    for(int i = 0 ; i < N ; i++){
        if(to_do & (1<<i)){
            ret = min(ret, get(idx+1,to_do-(1<<i)) + board[idx][i]);
        }
    }
    
    return ret;
}

int main(void){
    input();    
    memset(cashe,-1,sizeof(cashe));
    cout<<get(0,(1<<N)-1);
}