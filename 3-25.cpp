#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int arr[101][101] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct pos{
    int x;
    int y;
};

int bfs(int i , int j, int mexx , int mexy)
{
    queue <pos> que;
    int cnt = 1;
    
    pos nowidx = {i,j};
    pos searchidx;
    
    que.push(nowidx);
    arr[nowidx.x][nowidx.y] = 1;
    
    while(!que.empty())
    {
        nowidx = que.front();
        que.pop();
        
        for(int i = 0 ; i < 4 ;i++)
        {
            searchidx.x = nowidx.x + dx[i];
            searchidx.y = nowidx.y + dy[i];
            
            if(searchidx.x >= 0 && searchidx.x <= mexx && searchidx.y >= 0 && searchidx.y <= mexy)
            {
                if(arr[searchidx.x][searchidx.y] == 0)
                {
                    que.push(searchidx);
                    cnt++;
                    arr[searchidx.x][searchidx.y] = 1;
                }
            }
        }
    }
    
    return cnt;
    
}


int main(void)
{
    int n,m,k;
    cin>>n>>m>>k;
    pos pos1,pos2;
    int result_arr[10000];
    int cnt = 0;
    
    
    for(int i = 0 ; i < k ;i++)
    {
        cin>>pos1.y>>pos1.x>>pos2.y>>pos2.x;
        pos2.x--;
        pos2.y--;

        for(int a = pos1.x ; a <= pos2.x ; a++)
            for(int b = pos1.y ; b <= pos2.y ; b++)
                arr[a][b] = 1;
    }
    
    for(int i = 0 ; i < n ;i++)
    {
        for(int j = 0 ; j < m ;j++)
            if(arr[i][j] == 0)
            {
                result_arr[cnt++] = bfs(i,j,n-1,m-1);
            }
    }

    sort(result_arr,result_arr+cnt);
    
    cout<<cnt<<"\n";
    for(int i = 0 ; i < cnt ; i++)
        cout<<result_arr[i]<<" ";
    cout<<"\n";


    return 0;
}
