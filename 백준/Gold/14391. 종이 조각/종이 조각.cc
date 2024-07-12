#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,M;
int board[5][5];
int maxscore = -1;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%1d",&board[i][j]);
        }
    }
}

int get_num1(int idx, int y1 ,int y2){
    int num = 0;
    for(int i = y1 ; i <= y2 ; i++){
        num += board[idx][i];
        num *= 10;
    }
    if(num != 0) num /= 10;
    return num;
}
int get_num2(int idx, int x1 ,int x2){
    int num = 0;
    for(int i = x1 ; i <= x2 ; i++){
        num += board[i][idx];
        num *= 10;
    }
    if(num != 0) num = num / 10;
    return num;
}
int get(int x1, int y1 ,int x2, int y2){
    if(x1 > x2 || y1 > y2) return 0;
    int now_max = 0;
    for(int i = x1 ; i <= x2 ; i++){
        int n = get_num1(i,y1,y2);
        now_max = max(now_max, n + get(x1,y1,i-1,y2) + get(i+1,y1,x2,y2));
    }
    for(int i = y1 ; i <= y2 ; i++){
        int n = get_num2(i,x1,x2);
        now_max = max(now_max, n + get(x1,y1,x2,i-1) + get(x1,i+1,x2,y2));
    }

    return now_max;
}
int main(void){
    input();
    cout<<get(0,0,N-1,M-1);
}