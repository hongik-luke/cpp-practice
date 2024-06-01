#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int N,M;
int board[8][8];
int cctv[10][3]; // x y type;
int cctv_cnt = 0;
void input(){
    cin>>N>>M;
    int n;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>n;
            if(n == 6){
                board[i][j] = 6;
            }
            else if(n != 0){
                cctv[cctv_cnt][0] = i;
                cctv[cctv_cnt][1] = j;
                cctv[cctv_cnt][2] = n;
                cctv_cnt++;
            }
        }
    }
    
}
void go(int checkarr[] , int see, int cctv_num){
    int x = cctv[cctv_num][0]; 
    int y = cctv[cctv_num][1]; 
    int nx,ny;
    int cnt = 0;
    while(1){
        nx = x + dx[see]*cnt;
        ny = y + dy[see]*cnt;
        if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || board[nx][ny] == 6) break;
        cnt++;
        if(checkarr[nx] & (1<<ny)) checkarr[nx] -= (1<<ny);
    }    

}
int get(int remain_cctv, int checkarr[]){
    if(remain_cctv == -1){
        int cnt = 0;
        for(int i = 0 ; i  < N ; i++){
            for(int j = 0 ; j  < M ; j++){
                if(checkarr[i] & (1<<j) && board[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
    int ret = 98765;
    
    int checkarr1[N];
    for(int i = 0; i < 4 ; i++){
        for(int i = 0 ; i < N ; i++)
            checkarr1[i] = checkarr[i];
        
        if(cctv[remain_cctv][2] == 1){
            go(checkarr1, i, remain_cctv); 
        }
        else if(cctv[remain_cctv][2] == 2){
            if(i == 2 || i == 3) continue;
            go(checkarr1, i, remain_cctv); 
            go(checkarr1, i+2, remain_cctv);
        }
        else if(cctv[remain_cctv][2] == 3){
            go(checkarr1, i, remain_cctv); 
            go(checkarr1, (i+1)%4, remain_cctv);
        }
        else if(cctv[remain_cctv][2] == 4){
            go(checkarr1, i, remain_cctv); 
            go(checkarr1, (i+1)%4, remain_cctv);
            go(checkarr1, (i+2)%4, remain_cctv);
        }
        else if(cctv[remain_cctv][2] == 5){
            if(i == 1 || i == 2 || i == 3) continue;
            go(checkarr1, i, remain_cctv); 
            go(checkarr1, i+1, remain_cctv);
            go(checkarr1, i+2, remain_cctv);
            go(checkarr1, i+3, remain_cctv);
        }
        ret = min(ret, get(remain_cctv-1, checkarr1));   
    }
    return ret;
}
int main(void){
    input();
    int checkarr[N];
    memset(checkarr,0,sizeof(checkarr));
    for(int i = 0; i < N ; i++){
        checkarr[i] = (1<<M)-1;
    }

    cout<<get(cctv_cnt-1,checkarr);
    
}