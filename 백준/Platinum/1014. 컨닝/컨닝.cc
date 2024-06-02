#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N,M;
bool fboard[11][11];
void input(){
    cin>>N>>M;
    char n;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M ; j++){
            cin>>n;
            if(n == 'x') fboard[i][j] = false;
            else fboard[i][j] = true;
        }
    }
}
int cashe[10][10][1025][1025]; //인덱스 1 현재 줄번호/  인덱스 2 현재열번호// 인덱스 3 현재줄 정보 / 인덱스 4 앞에 줄 정보
int get(int x, int y, int now_low, int before_low){
    if(x >= N) return 0;
    if(y >= M) return get(x+1,0,0,now_low);
    
    //cout<<x<<y<<" "<<now_low<<" "<<before_low<<"\n";
    int& ret = cashe[x][y][now_low][before_low];
    if(ret != -1) return ret;
    ret = 0;
    if(fboard[x][y]){
        //앞줄
        if(y-1 < 0 || (before_low & (1<<(y-1))) == 0){
            if(y+1 > M-1 || (before_low & (1<<(y+1))) == 0 ){
                
                int new_low = now_low + (1<<y);
                ret = max(ret, 1+get(x, y+2, new_low, before_low));
                
            }
        }
    }  
    ret = max(ret, get(x, y+1, now_low, before_low));
    return ret;
}



int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ;i++){
        memset(cashe,-1,sizeof(cashe));
        input();
        cout<<get(0,0,0,0)<<"\n";
    }
}