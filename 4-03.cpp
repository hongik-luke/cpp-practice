#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[51][51];
int xpos[8] = {-1,-1,-1,0,0,1,1,1};
int ypos[8] = {-1,0,1,-1,1,-1,0,1};
struct pos{
    int x;
    int y;
};
void bfs(int i, int j ,int m ,int n)
{
    queue <pos> pq;
    pos nowpos = {i,j};
    pos searchpos;
    map[i][j] = 0;
    pq.push(nowpos);
    
    while(!pq.empty())
    {
        nowpos = pq.front();
        pq.pop();
        
        for(int i = 0 ; i < 8 ; i++){
            searchpos.x = nowpos.x + xpos[i];
            searchpos.y = nowpos.y + ypos[i];
            
            if(searchpos.x >= 0 && searchpos.x <= m-1 && searchpos.y >= 0 && searchpos.y <= n-1)
            {
                if(map[searchpos.x][searchpos.y] == 1)
                {
                    pq.push(searchpos);
                    map[searchpos.x][searchpos.y] = 0;
                }
            }
        }
    }
    
    return;
}
int main(void)
{
    int n,m;
    int cnt;
    while(1)
    {
        cin>>n>>m;
        if(n == 0 && m == 0) break;
        cnt = 0;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                cin>>map[i][j];
                
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
            {
                if(map[i][j] == 1)
                {
                    bfs(i,j,m,n);
                    cnt++;
                }
            }
        
        cout<<cnt<<"\n";
    }
    
    return 0;
    
}