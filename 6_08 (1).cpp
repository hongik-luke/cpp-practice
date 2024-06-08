#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N,M;
char making[17];
char board[17];

void input(){
    cin>>N>>M;
    char n;
    for(int i = 0 ; i < M ; i++){
        cin>>n;
        board[i] = n;
    }
    sort(board,board+M);
}
void get(int now, int beforeidx, int mo ,int notmo){
    if(now == N){
        if(mo < 1 || notmo < 2) return;
        
        for(int i = 0 ; i < N ; i++)
            cout<<making[i];
        cout<<"\n";
        
        return;
    }
    for(int i = beforeidx+1 ; i < M ; i++){
        if(board[i] == 'a' || board[i] == 'i' || board[i] == 'o' || board[i] == 'u' || board[i] == 'e'){
            making[now] = board[i];
            get(now+1, i, mo+1 ,notmo);
        }
        else{
            making[now] = board[i];
            get(now+1, i, mo ,notmo+1);
        }
    }
}
int main(void){
    input();
    get(0,-1,0,0);
}
