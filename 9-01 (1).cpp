#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;

int N,M,K;
int arr[1010][1010][3];
int board[1010][1010][3];
void input(){
    cin>>N>>M;
    cin>>K;
    char c;
    for(int i = 1 ; i <= N ; i++){
        for(int j  = 1 ; j <= M ; j++){
            arr[i][j][0] = arr[i][j-1][0];
            arr[i][j][1] = arr[i][j-1][1];
            arr[i][j][2] = arr[i][j-1][2];
            
            cin>>c;
            if(c == 'J') arr[i][j][0]++;
            else if(c == 'O') arr[i][j][1]++;
            else arr[i][j][2]++;
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        for(int j  = 1 ; j <= M ; j++){
            board[i][j][0] = board[i-1][j][0] + arr[i][j][0];
            board[i][j][1] = board[i-1][j][1] + arr[i][j][1];
            board[i][j][2] = board[i-1][j][2] + arr[i][j][2];
        }
    }
}
void query(){
    int x1,y1,x2,y2;
    int result[3];
    for(int i = 0 ; i < K ; i++){
        cin>>x1>>y1>>x2>>y2;
        for(int j = 0 ; j < 3 ; j++){
            result[j] = 0;
            result[j] = board[x2][y2][j] + board[x1-1][y1-1][j] - board[x1-1][y2][j] - board[x2][y1-1][j];
            cout<<result[j]<<" ";
            
        }
        cout<<"\n";
    }
}
int main(void){
    FASTIO;
    input();
    query();
}