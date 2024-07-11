#include <iostream>
#include <queue>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int N,M,X,Y,K;
int board[23][23];
int dice[6];
int arr[1010];
void input(){
    cin>>N>>M>>X>>Y>>K;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            cin>>board[i][j];
    
    for(int i = 0 ; i < K ; i++){
        cin>>arr[i];
    }        
}
void change_dice(int idx){
    // 1234
    //cout<<"idx) "<<idx<<"\n";
    //for(int i = 0 ; i < 6 ; i++){
    //    cout<<dice[i];
    //} 
    //cout<<"\n";
    if(idx%2 == 1){
        swap(dice[0],dice[idx]);
        swap(dice[5],dice[idx+1]);
        swap(dice[idx],dice[idx+1]);
    }
    else{
        swap(dice[0],dice[idx]);
        swap(dice[5],dice[idx-1]);
        swap(dice[idx],dice[idx-1]);
    }
}
bool check(int idx){
    int nx = X + dx[idx-1];
    int ny = Y + dy[idx-1];
    if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) return false;
    X = nx;
    Y = ny;
    change_dice(idx);
    if(board[X][Y] == 0) board[X][Y] = dice[0];
    else{
        dice[0] = board[X][Y];
        board[X][Y] = 0;
    }
    
    return true;
}
void print(){
    for(int i = 0 ; i  < K ;  i++){
        if(check(arr[i])){
            //for(int i = 0 ; i < 6 ; i++){
            //    cout<<dice[i];
            //} 
            //cout<<"\n";
            cout<<dice[5]<<"\n";
            
        }
    }
}
int main() {
    FASTIO;
    input();
    print();
}

