#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

int dx[3] = {0,1,1}; //가로0 세로1 대각선2
int dy[3] = {1,0,1};
int Map[16][16];
bool check[16][16];
int n;
int cnt = 0;
void DFS(int nowx, int nowy, int tipe){
    if(nowx == n-1 && nowy == n-1)
    {
        cnt++;
        return;
    }
    
    for(int i = 0 ; i < 3; i++){
        int newx = nowx + dx[i];
        int newy = nowy + dy[i];
        if(Map[newx][newy] == 1 || newx == n || newy ==n)
            continue;
        if(i == 2){
            if(Map[newx][newy] == 1 || Map[newx-1][newy] == 1|| Map[newx][newy-1] == 1)
                continue;
        }
        if(tipe == 1 && i == 0)
            continue;
        if(tipe == 0 && i == 1)
            continue;

        DFS(newx,newy,i);
        
    }
    return;
}

int main(void){
    cin>>n;
    for(int i = 0 ; i < n ;i++)
        for(int j = 0 ; j < n ;j++)
            cin>>Map[i][j];
    DFS(0,1,0);
    cout<<cnt;
}