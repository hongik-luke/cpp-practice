#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

struct pos{
    int x;
    int y;
    int breaked;
};

int Map[1001][1001];
int result_Map[1001][1001];
bool check[1001][1001][2];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int BFS(){
    pos nowidx, newidx;
    queue <pos> pq;
    pq.push({0,0,0});
    result_Map[0][0] = 1;
    check[0][0][0] = true;
    check[0][0][1] = true;
    while(!pq.empty()){
        nowidx = pq.front();
        pq.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            newidx.x = nowidx.x + dx[i];
            newidx.y = nowidx.y + dy[i];
            newidx.breaked = nowidx.breaked;
            
            if(newidx.x < 0 || newidx.x > n-1 || newidx.y < 0 || newidx.y > m-1 || check[newidx.x][newidx.y][newidx.breaked])
                continue;
            if(Map[newidx.x][newidx.y] == 1 && newidx.breaked == 1)
                continue;
            
            if(Map[newidx.x][newidx.y] == 1)
            {
                newidx.breaked = 1; 
            }
            
            if(newidx.breaked == 0){
                check[newidx.x][newidx.y][0] = true;    
                check[newidx.x][newidx.y][1] = true;    
            }
            else{
                check[newidx.x][newidx.y][1] = true;    
            }
            
            result_Map[newidx.x][newidx.y] = result_Map[nowidx.x][nowidx.y] +1;
            pq.push(newidx);

            if(newidx.x == n-1 &&newidx.y == m-1){
                return result_Map[newidx.x][newidx.y];
            }
        }
    }
    return -1;
}

int main(void){
    cin>>n>>m;
    string s;
    for (int i = 0; i <n; i++)
	{
		cin >> s;
		for (int j = 0; j <m; j++)
			Map[i][j] = s[j] - '0';
	}
    if(n == 1 && m == 1)
    {
        cout<<1;
        return 0;
    }
    cout<<BFS()<<"\n";
}
            