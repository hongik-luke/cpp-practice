#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
char board[23][23];
bool check[30];
int max_ = 0;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int N,M;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
        }
    }
}
void get(int x ,int y,int temp){
    if(temp > max_) max_ = temp;
    
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int num = board[nx][ny] - 'A';
        if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || check[num]) continue;

        check[num] = true;
        get(nx,ny,temp+1);
        check[num] = false;
    }
}
int main(void){
    input();
    memset(check,false,sizeof(check));
    
    int num = board[0][0] - 'A';
    check[num] = true;
    get(0,0,1);
    
    cout<<max_;
}