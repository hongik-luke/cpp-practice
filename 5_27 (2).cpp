#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N,K;
int two_board[25];
void maketwo(){
    int now = 1;
    for(int i = 0 ; i < 25 ; i++){
        two_board[i] = now;
        now = now*2;
    }
}

int get(){
    int n = 24;
    while(n != -1){
        if(K == 1) break;
        
        if(N == two_board[n]) return 0;
        else if(N > two_board[n]){
            N = N - two_board[n];
            K--;
        }
        n--;
    }
    
    int a;
    for(int i = 0 ; i < 25 ; i++){
        if(N <= two_board[i]){
            a = i;
            break;
        }
    }
    return two_board[a] - N;
}



int main(void){
    cin>>N>>K;
    maketwo();
    cout<<get();
}


