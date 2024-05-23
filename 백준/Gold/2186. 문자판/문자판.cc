#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N,M,K;
char board[105][105];
int cashe[85][105][105];
string word;
int len;

void input(){
    cin>>N>>M>>K;
    char n ;
    for(int i = 0 ; i < N;  i++)
        for(int j = 0 ; j < M ; j++)
            cin>>board[i][j];
    cin>>word;
    len = word.size();
}

int getnum(int next, int x, int y){
    if(next == len) return 1;
    
    int& ret = cashe[next][x][y];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i = 0 ; i < 4 ; i ++){
        for(int j = 1 ; j <= K ; j++){
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;
            
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || board[nx][ny] != word[next]) continue;
            
            ret += getnum(next+1,nx,ny);
        }
    }

    
    return ret;
}

int main(void){
    memset(cashe,-1,sizeof(cashe));
    int result = 0;
    input();
    for(int i = 0 ; i < N;  i++)
        for(int j = 0 ; j < M ; j++)
            if(word[0] == board[i][j]){
                result += getnum(1,i,j);
            }
    cout<<result;
}
