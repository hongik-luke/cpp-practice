#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int N,M;
int board[9][9];
bool check[9][9];
vector<pair<int,int>> v;
int vlen;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                v.push_back(make_pair(i,j));
            }
        }
    }
    vlen = v.size();
}
int mincnt = 999;
void get(int idx){
    if(idx == vlen){
        //cout<<idx;
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(check[i][j] == false && board[i][j] == 0) cnt++;
            }
        }
    
        mincnt = min(mincnt, cnt);
        return;
    }
    
    bool nowcheck[9][9];
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            nowcheck[i][j] = check[i][j];
    
    
            
    if(board[v[idx].first][v[idx].second] == 5){
        int x = v[idx].first;
        int y = v[idx].second;
        for(int i = 0 ; i < 4 ; i++){
            int cnt = 1;
            while(1){
                int nx = x + dx[i]*cnt;
                int ny = y + dy[i]*cnt;
                if(nx > N-1 || nx < 0 || ny > M-1 || ny < 0 || board[nx][ny] == 6) break;
                check[nx][ny] = true;
                cnt++;
            }
        }
        get(idx+1);
    }
    else if(board[v[idx].first][v[idx].second] == 4){
        int x = v[idx].first;
        int y = v[idx].second;
        for(int i = 0 ; i < 4 ; i++){
            //초기화
            for(int i1 = 0 ; i1 < N ; i1++)
                for(int j1 = 0 ; j1 < M ; j1++)
                    check[i1][j1] = nowcheck[i1][j1];
            
            
            for(int j = 0 ; j < 4 ; j++){
                if((i+j)%4 == 3) continue;
                int cnt = 1;
                while(1){
                    int nx = x + dx[j]*cnt;
                    int ny = y + dy[j]*cnt;
                    if(nx > N-1 || nx < 0 || ny > M-1 || ny < 0 || board[nx][ny] == 6) break;
                    check[nx][ny] = true;
                    cnt++;
                }
            }
            get(idx+1);
        }
    }
    
    else if(board[v[idx].first][v[idx].second] == 3){
        int x = v[idx].first;
        int y = v[idx].second;
        for(int i = 0 ; i < 4 ; i++){
            //초기화
            for(int i1 = 0 ; i1 < N ; i1++)
                for(int j1 = 0 ; j1 < M ; j1++)
                    check[i1][j1] = nowcheck[i1][j1];
            
            
            for(int j = 0 ; j < 4 ; j++){
                if((i+j)%4 == 3 || (i+j)%4 == 2) continue;
                int cnt = 1;
                while(1){
                    int nx = x + dx[j]*cnt;
                    int ny = y + dy[j]*cnt;
                    if(nx > N-1 || nx < 0 || ny > M-1 || ny < 0 || board[nx][ny] == 6) break;
                    check[nx][ny] = true;
                    cnt++;
                }
            }
            get(idx+1);
        }
    }
    
    else if(board[v[idx].first][v[idx].second] == 2){
        int x = v[idx].first;
        int y = v[idx].second;
        for(int i = 0 ; i < 2 ; i++){
            //초기화
            for(int i1 = 0 ; i1 < N ; i1++)
                for(int j1 = 0 ; j1 < M ; j1++)
                    check[i1][j1] = nowcheck[i1][j1];
            
            for(int j = 0 ; j < 4 ; j++){
                if((i+j)%4 == 3 || (i+j)%4 == 1) continue;
                int cnt = 1;
                while(1){
                    int nx = x + dx[j]*cnt;
                    int ny = y + dy[j]*cnt;
                    if(nx > N-1 || nx < 0 || ny > M-1 || ny < 0 || board[nx][ny] == 6) break;
                    check[nx][ny] = true;
                    cnt++;
                }
            }
            
            get(idx+1);
        }
    }
    
    else if(board[v[idx].first][v[idx].second] == 1){
        int x = v[idx].first;
        int y = v[idx].second;
        for(int i = 0 ; i < 4 ; i++){
            //초기화
            for(int i1 = 0 ; i1 < N ; i1++)
                for(int j1 = 0 ; j1 < M ; j1++)
                    check[i1][j1] = nowcheck[i1][j1];

            int cnt = 1;
            while(1){
                int nx = x + dx[i]*cnt;
                int ny = y + dy[i]*cnt;
                if(nx > N-1 || nx < 0 || ny > M-1 || ny < 0 || board[nx][ny] == 6) break;
                check[nx][ny] = true;
                cnt++;
            }
            
            get(idx+1);
        }
    }

}
int main(void){
    input();
    memset(check,false,sizeof(check));
    get(0);
    cout<<mincnt;
}