#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N,P;
int not_on = 0;

int board[20][20]; // i번째 발전소가 j번째 발전소를 고치는 비용
int cashe[1<<16];

void input(){
    cin>>N;
    for(int i = 0 ;  i < N ; i++){
        for(int j = 0 ;  j < N ; j++){
            cin>>board[i][j];
        }
    }
    char n;
    int on_cnt = 0;
    for(int i = 0 ;  i < N ; i++){
        cin>>n;
        if(n == 'N') not_on += (1<<i);
        else on_cnt++;
    }
    cin>>P;
    P = P-on_cnt;
}

int get(int down_now, int P){
    if(P <= 0) return 0;

    int& ret = cashe[down_now];
    if(ret != -1) return ret;
    ret = 987654;
    
    for(int i = 0 ; i < N ; i++){
        //꺼져있는 i번째를 키는 연산
        if(down_now & (1<<i)){
            //현재 켜져있는 걸 모두 찾아서 i번째를 최소비용으로 킬 수 있는 경우를 찾는다.
            int min_ = 987654;
            for(int j = 0 ; j < N ; j++){
                if((down_now & (1<<j)) == 0){
                    if(board[j][i] < min_){
                        min_ = board[j][i];
                    }
                }
                
            }
            ret = min(ret, get(down_now-(1<<i), P-1) + min_);
        }
    }
    return ret;
}

int main(void){
    input();    
    memset(cashe,-1,sizeof(cashe));
    int n = get(not_on,P);
    if(n >= 987654) cout<<-1;
    else cout<<n;
}










