#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};
struct shark{
    bool yes;
    int x;
    int y;
    int speed;
    int d;
    int weight;
};
int N,M;

shark board[103][103];

void input(){
    int K;
    cin>>N>>M>>K;
    int n1,n2,n3,n4,n5;
    for(int i = 0 ; i < K ; i++){
        cin>>n1>>n2>>n3>>n4>>n5;
        board[n1-1][n2-1].yes = true;
        if(n4 == 1 || n4 == 2){
            n3 = n3 % ((N-1)*2);
            board[n1-1][n2-1].speed = n3;
        }
        if(n4 == 3 || n4 == 4){
            n3 = n3 % ((M-1)*2);
            board[n1-1][n2-1].speed = n3;
        }
        board[n1-1][n2-1].d = n4;
        board[n1-1][n2-1].weight = n5;

    }
    
}
shark new_board[103][103];
void all_shark_move(){
    memset(new_board,0,sizeof(new_board));
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i][j].yes){
                int nx,ny,nd;
                nx = i + dx[board[i][j].d]*board[i][j].speed;
                ny = j + dy[board[i][j].d]*board[i][j].speed;
                nd = board[i][j].d;
                //cout<<nx<<ny<<nd;
                if(nx > N-1){
                    nx = (N-1)*2 - nx;
                    if(nd == 1 || nd == 3) nd++;
                    else nd--;
                }
                else if(ny > M-1){
                    ny = (M-1)*2 - ny;
                    if(nd == 1 || nd == 3) nd++;
                    else nd--;
                }
                
                if(nx < 0){
                    nx = -nx;
                    if(nd == 1 || nd == 3) nd++;
                    else nd--;
                }
                else if(ny < 0){
                    ny = -ny;
                    if(nd == 1 || nd == 3) nd++;
                    else nd--;
                }
                
                if(nx > N-1){
                    nx = (N-1)*2 - nx;
                    if(nd == 1 || nd == 3) nd++;
                    else nd--;
                }
                else if(ny > M-1){
                    ny = (M-1)*2 - ny;
                    if(nd == 1 || nd == 3) nd++;
                    else nd--;
                }
                if(new_board[nx][ny].yes && new_board[nx][ny].weight > board[i][j].weight) continue;
                else{
                    new_board[nx][ny].yes = true;
                    new_board[nx][ny].speed = board[i][j].speed;
                    new_board[nx][ny].d = nd;
                    new_board[nx][ny].weight = board[i][j].weight;
                }
                
                //cout<<nx+1<<" "<<ny+1<<" "<<new_board[nx][ny].speed<<" "<<nd<<" "<<new_board[nx][ny].weight<<"\n";
            }
        }
    }
    //cout<<"!\n";
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            board[i][j] = new_board[i][j];

}
int get(){
    int ret = 0;
    for(int j = 0; j < M ; j++){
        for(int i = 0; i < N ; i++){
            // 1 물고기 잡기
            if(board[i][j].yes){
                ret += board[i][j].weight;
                //cout<<board[i][j].weight<<"!";
                board[i][j].yes = false;
                board[i][j].speed = 0;
                board[i][j].d = 0;
                board[i][j].weight = 0;
                
                break;
            }
        }
        // 2 움직이기
        all_shark_move();
    }
    return ret;
}
int main(void){
    input();
    cout<<get();
    
}