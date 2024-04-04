//7562

#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

struct pos{
    int x;
    int y;
};

int arr[301][301];
bool visited[301][301];
int dx[8] = { -1,-2,-1,-2,1,1,2,2 };
int dy[8] = { -2,-1,2,1,2,-2,1,-1 };


void bfs(int size, pos start,pos finish){
    
    pos nowpos,newpos;
    
    queue <pos> pq;
    pq.push(start);
    visited[start.x][start.y] = true;
    arr[start.x][start.y] = 0;
    
    while(!pq.empty()){
        if(visited[finish.x][finish.y] == true)
            break;
        nowpos = pq.front();
        pq.pop();
        for(int i = 0 ; i < 8 ; i++)
        {
            newpos.x = nowpos.x + dx[i];
            newpos.y = nowpos.y + dy[i];
            if(newpos.x >= 0 && newpos.x <= size-1 && newpos.y >= 0 && newpos.y <= size-1 )
            {
                if(visited[newpos.x][newpos.y] == false)
                {
                    visited[newpos.x][newpos.y] = true;
                    arr[newpos.x][newpos.y] = arr[nowpos.x][nowpos.y] +1;
                    pq.push(newpos);
                }
            }
        }
    }
    
    cout<<arr[finish.x][finish.y]<<"\n";
}




int main(void)
{
    int n,size;
    cin>>n;
    pos start,finish;
    for(int i =0 ; i < n ; i++)
    {
        cin>>size;
        for(int i = 0 ; i < size ; i++)
            for(int j = 0 ; j < size ; j++)
            {
                visited[i][j] = false;
                arr[i][j] = 0;
            }
        cin>>start.x>>start.y;
        cin>>finish.x>>finish.y;
        
        bfs(size,start,finish);
    }
}