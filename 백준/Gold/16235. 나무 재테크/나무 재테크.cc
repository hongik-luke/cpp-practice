#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
vector<int> tree[13][13];
int board[13][13];
int plus_[13][13];
int N,M,K;
void input(){
    cin>>N>>M>>K;

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++){
            cin>>plus_[i][j];
            board[i][j] = 5;
        }
    for(int i = 0 ; i < M ; i++){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        tree[n1][n2].push_back(n3);
    }

}
int main(void){
    input();
    for(int k = 0 ;  k < K ; k++){
        // 봄
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                int for_summer = 0;
                int cnt = 0;
                int len = tree[i][j].size();
                if(len == 0 ) continue;
                for(int t = 0 ; t < len ; t++){
                    if(tree[i][j][t] <= board[i][j]){
                        board[i][j] -= tree[i][j][t];
                        tree[i][j][t]++;
                    }
                    else{
                        for_summer += tree[i][j][t]/2;
                        cnt++;
                    }
                }
                
                //여름 +봄 삭제
                board[i][j] += for_summer;
                for(int t = 0 ; t < cnt ; t++){
                    tree[i][j].pop_back();
                }
            }
        }
        //가을 for문 5중첩 이거맞나 시발?
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                int len = tree[i][j].size();
                for(int t = 0 ; t < len ; t++){
                    if(tree[i][j][t]%5 == 0){
                        int nx,ny;
                        for(int m = 0 ; m < 8 ; m++){
                            nx = dx[m] + i;
                            ny = dy[m] + j;
                            if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        //겨울 양분주기 및 정렬
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                board[i][j] += plus_[i][j];
                sort(tree[i][j].begin(),tree[i][j].end());
            }
        }
        
        
    }
    int result = 0;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            result += tree[i][j].size();
    cout<<result;
}