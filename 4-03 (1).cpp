#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool vis[1001][1001];

struct Node{
    int screan; 
    int clip; 
    int times;
};

void bfs(int find)
{
    queue <Node> pq;
    pq.push({2,1,2});
    Node nowpos;
    Node newpos;
    
    for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            vis[i][j]=false;
            
    while(!pq.empty())
    {
        nowpos = pq.front();
        pq.pop();
        vis[nowpos.screan][nowpos.clip] = true;
        
        if(nowpos.screan == find)
        {
            cout<<nowpos.times;
            return;
        }
        
        if(!vis[nowpos.screan][nowpos.screan] && nowpos.screan > 0 && nowpos.screan <= 1000)
            pq.push({nowpos.screan,nowpos.screan,nowpos.times+1});
        if(nowpos.screan+nowpos.clip <= 1000  && !vis[nowpos.screan + nowpos.clip][nowpos.clip] )
            pq.push({nowpos.screan+nowpos.clip,nowpos.clip,nowpos.times+1});
        if(nowpos.screan-1 >= 0 &&!vis[nowpos.screan-1][nowpos.clip] )
            pq.push({nowpos.screan-1,nowpos.clip,nowpos.times+1});
        
    }
}

int main(void)
{
    int n;
    cin>>n;
    bfs(n);
    return 0;
}